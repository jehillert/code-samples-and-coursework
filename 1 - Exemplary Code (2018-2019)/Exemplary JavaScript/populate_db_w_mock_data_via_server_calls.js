/* eslint-disable import/no-extraneous-dependencies */
const axios = require('axios');
const cmd = require('node-cmd');
const faker = require('faker');
const moment = require('moment');
const Promise = require('bluebird');

const getAsync = Promise.promisify(cmd.get, { multiArgs: true, context: cmd });

faker.seed(123);

const aTimeLaterToday = () => {
  const now = moment();
  const midnight = moment().endOf('hour');
  let timeInBetween = faker.date.between(now, midnight);
  timeInBetween = moment(timeInBetween).format('YYYY-MM-DD HH:mm');
  // timeInBetween = moment(timeInBetween).format('YYYY-MM-DD HH:mm:ss');
  return timeInBetween;
};
const generateUserEntries = (user, minEntries = 15, maxEntries = 30) => {
  const entries = [];

  const numOfUserEntries = faker.random.number({ min: minEntries, max: maxEntries });

  for (let e = 0; e < numOfUserEntries; e += 1) {
    const creationDate = moment(faker.date.past()).format('YYYY-MM-DD HH:mm');
    const releaseDate = Math.random() < 0.5
                    ? aTimeLaterToday()
                    : moment(faker.date.future()).format('YYYY-MM-DD HH:mm');

    const entry = {
      userId: user.userId,
      creationDate,
      releaseDate,
      description: faker.lorem.words(Math.floor((Math.random() * 10))),
      content: faker.lorem.sentence(),
    };

    // console.log(entry);
    entries.push(entry);
  }
  return entries;
};
const generateUsers = (numOfUsers = 100, users = []) => {
  for (let i = 1; i <= numOfUsers; i += 1) {
    const user = {
      userId: i,
      username: faker.internet.userName(),
      password: faker.internet.password(),
    };
    user.entries = generateUserEntries(user);
    // console.log(`[${user.userId}, '${user.username}', '${user.password}'],`);
    users.push(user);
  }
  return users;
};

const numOfUsers = 25;
console.clear();

getAsync('mysql -u root <schema_mysql.sql')
  .then(() => { console.log('db tables cleared'); })
  .then(() => generateUsers(numOfUsers))
  // add each user to users table
  .then(users => Promise.each(
    users, user => axios.post(
      'http://localhost:3000/api/timelockr_dev_db/signup',
      {
        username: user.username,
        password: user.password,
      },
    )
    .then(() => console.log(user.username, user.password))
    .then(() => (Promise.each(
        user.entries,
        entry => axios.post('http://localhost:3000/api/timelockr_dev_db/entries', {
            userId: entry.userId,
            creationDate: entry.creationDate,
            releaseDate: entry.releaseDate,
            description: entry.description,
            content: entry.content,
          })
        .then(() => console.log(
          entry.userId,
          entry.creationDate,
          entry.releaseDate,
          entry.description,
          entry.content,
        )),
      ))),
    ).then(() => console.log('done')))
  .catch(err => console.log('cmd err', err));
      // console.log(user.username, user.password);
