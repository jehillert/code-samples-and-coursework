var mysql = require('mysql');

var connection = mysql.createConnection({
  user     : 'root',
  password : '',
  database : 'pomeranian_database'
});

connection.connect()

module.exports = connection;
