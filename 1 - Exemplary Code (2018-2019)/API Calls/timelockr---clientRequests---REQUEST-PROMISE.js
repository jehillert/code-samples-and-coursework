require('dotenv').config();
const debug = require('debug')('scripts:ClientRequests');
const rp = require('request-promise');
const errors = require('request-promise/errors');
const Promise = require('bluebird');

module.exports.createNewUser = (user, pass) => {
  var options = {
    method: 'POST',
    url: 'http://localhost:3000/api/keepsafe/signup', // uri:
    headers: { 'Content-Type': 'application/json' },
    body: { username: user, password: pass },
    json: true
  };
  return rp(options)
    .then(() => {
      return {userCreated: true, message: 'New user successfully created.'};l
    })
    .catch(error => {
      if (error.statusCode === 409) {
        return {userCreated: false, message: 'Username taken.  Please select another'};
      } else {
        alert(`ERROR ${error.statusCode} @ function 'createNewUser().'\nCAUSE: ${error.cause}`)
      }
    });
};

module.exports.retrieveEntries = username => {
  var options = {
    uri: `http://localhost:3000/api/keepsafe/secrets/`,
    headers: {
      'User-Agent': 'Request-Promise',
      'Content-Type': 'application/json'
    },
    qs: { username: username },
    json: true
  };
  return rp(options)
    .then(results => results)
    .catch(errors.StatusCodeError, reason => {
      console.error(
        `ERROR @ function 'retrieveEntries().'\n${reason.statusCode}`
      );
    })
    .catch(errors.RequestError, reason => {
      console.error(`ERROR @ function 'retrieveEntries().'\n${reason.cause}`);
    });
};

module.exports.verifyUser = (user, pass) => {
  var options = {
    method: 'POST',
    url: `http://localhost:3000/api/keepsafe/login`,
    headers: {
      'User-Agent': 'Request-Promise',
      'Content-Type': 'application/json'
    },
    body: { username: user, password: pass },
    json: true
  };
  return rp(options)
    .then(() => {
      return {userAuthenticated: true, message: 'User authenticated.'};l
    })
    .catch(errors.StatusCodeError, reason => {
      console.error(
        `ERROR @ function 'verifyUser().'\n${reason.statusCode}`
      );
    })
    .catch(errors.RequestError, reason => {
      console.error(`ERROR @ function 'verifyUser().'\n${reason.cause}`);
    });
};
