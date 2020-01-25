var mysql = require('mysql');

var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'root',
  password : '',
  database : 'vegetableList'
});

connection.connect();

exports.getVegetableList = (callback) => {
  connection.query('select * from vegetables', (error, results) => {
    console.log(results)
    if (error) {
      callback(error)
    } else {
      callback(null, results);
    }
  });
};

exports.addFoodItem = (food, quantity, callback) => {
  connection.query('insert into vegetables (food, quantity) values (?, ?)', [food, quantity], (error, results) => {
    callback(error, results);
  });
};
