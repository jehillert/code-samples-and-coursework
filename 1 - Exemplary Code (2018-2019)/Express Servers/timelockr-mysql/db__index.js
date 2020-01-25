/* eslint-disable key-spacing */
const chalk = require('chalk');
const debug = require('debug')(chalk.hex('#8ecfe3').bgHex('#08134A')(`db:${process.env.DB}`));
const mysql = require('mysql');
const Promise = require('bluebird');

Promise.promisifyAll(require('mysql/lib/Connection').prototype);

debug(chalk.white('Database Status (MySQL):'), chalk.white.bold.bgRed(' DEVELOPMENT MODE '), chalk.inverse(' Debugging Enabled '));
const mysqlConfig = {
  host     : process.env.MYSQL_DB_HOST,
  user     : process.env.MYSQL_DB_USER,
  password : process.env.MYSQL_DB_PASS,
  database : process.env.MYSQL_DB_NAME,
};

debug(mysqlConfig);

const connection = mysql.createConnection(mysqlConfig);
connection.connect();

module.exports = connection;
