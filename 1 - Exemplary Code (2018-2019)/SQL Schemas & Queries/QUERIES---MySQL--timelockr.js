const debug = require('debug')('db:models');
const chalk = require('chalk');
const db = require('../db');

module.exports = {
  general: {
    delete: params => db
      .queryAsync('DELETE FROM ?? WHERE ?? = ?', params)
      .catch(error => debug(chalk.red.bold('Error:'), error)),
    put: params => db.queryAsync('UPDATE IGNORE ?? SET ?? = ? WHERE ?? = ?', params)
      .catch(error => debug(chalk.red.bold('Error:'), error)),
  },

  users: {
    get: params => db.queryAsync('SELECT * FROM ?? WHERE ?? = ?', params),
    post: params => db.queryAsync('INSERT INTO ??(??, ??, ??) VALUES (?, ?, ?)', params),
  },

  entries: {
    get: params => db.queryAsync('SELECT * FROM ?? LEFT JOIN ?? USING (??) WHERE ?? = ? ORDER BY ?? ASC', params)
      .catch(error => debug(chalk.red.bold('Error:'), error)),
    post: params => db.queryAsync('INSERT INTO ??(entry_id, ??, ??, ??, ??, ??) VALUES (0, ?,?,?,?,?)', params),
  },
};
