const chalk = require('chalk');
const debug = require('debug')(chalk.hex('#38A53C').bgHex('#000000')('server:controllers'));
const hasher = require('pbkdf2-password')();
const helpers = require('./helpers/helpers');
const models = require('./models');

function deleteFromTable(req, res) {
  const params = helpers.getQueryParams(req);
  models.general
    .delete(params)
    .then(() => res.sendStatus(201))
    .catch(error => debug('Error', error));
}

function updateField(req, res) {
  const params = helpers.getQueryParams(req);
  models.general
    .put(params)
    .then(() => res.sendStatus(201))
    .catch(error => debug('Error', error));
}

module.exports = {
  signin: {
    post: (req, res) => models.users.get(['users', 'username', req.body.username])
        .then((user) => {
          let parsedUser = user;
          parsedUser.parseSqlResult = function parseSqlResult() {
            return JSON.parse(JSON.stringify(this[0]));
          };
          parsedUser = parsedUser.parseSqlResult();
          if (!parsedUser.username) throw new Error('Invalid username.');
          return parsedUser;
        })
        .tap((user) => {
          hasher({ password: req.body.password, salt: user.salt }, (err, pass, salt, hash) => {
            if (err) throw err;
            if (hash !== user.hash) throw new Error('Invalid password.');
            req.session.regenerate(() => {
              req.session.user = user;
              req.session.save();
            });
          });
        })
        .then(user => res.status(202).send({ userId: user.user_id }))
        .catch(error => debug('Error', error)),
  },

  logout: {
    get: (req, res) => req.session.destroy()
      .then(() => res.status(200).json({ message: 'Logout successful.' }))
      .catch(error => debug('Error', error)),
  },

  users: {
    put: (req, res) => updateField(req, res),

    delete: (req, res) => deleteFromTable(req, res),
  },

  entries: {
    get: (req, res) => models.entries.get([
        'entries',
        'users',
        'user_id',
        'username',
        req.query.username,
        'release_date',
      ])
        .tap(results => debug('\n\nEntries - UNSORTED:\n\n%O', results))
        .then(results => helpers.sortEntries(results))
        .then(results => res.send(results))
        .catch(error => debug('Error', error)),

    put: (req, res) => models.general.put([
        'entries',
        'release_date',
        req.body.data.releaseDate,
        'entry_id',
        req.body.data.entryId,
    ])
      .then(() => res.sendStatus(201))
      .catch(error => debug('Error', error)),

    post: (req, res) => models.entries.post([
      'entries',
      'user_id',
      'creation_date',
      'release_date',
      'description',
      'content',
      req.body.userId,
      req.body.creationDate,
      req.body.releaseDate,
      req.body.description,
      req.body.content,
    ])
      .then(() => res.sendStatus(201))
      .catch(error => debug('Error', error)),

    delete: (req, res) => models.general
        .delete(['entries', 'entry_id', req.body.entryId])
        .then(() => res.sendStatus(201))
        .catch(error => debug('Error', error)),
  },

  signup: {
    post: (req, res) => models.users
      .post([
        'users',
        'username',
        'hash',
        'salt',
        req.body.username,
        req.body.hash,
        req.body.salt,
      ])
      .then(() => res.sendStatus(201))
      .catch(() => res.sendStatus(409)),
      // .then(() => res.status(201).json({message: 'New user successfully created.'}))
  },
};
