var db = require('../db');

module.exports = {
  pomeranians: {
    get: function (callback) {
      var queryStr = 'select * from pomeranians \
                      order by id desc';
      db.query(queryStr, function(err, results) {
        callback(err, results);
      });
    },
    post: function (params, callback) {
      var queryStr = 'insert into pomeranians(name, description) \
                      value (?, ?)';
      db.query(queryStr, params, function(err, results) {
        callback(err, results);
      });
    },
    put: function (params, callback) {
      let queryStr = '';
      if (params.name) {
        queryStr = `UPDATE pomeranians SET name = '${params.name}' WHERE id = ${params.id}`;
      }
      if (params.name && params.description) {
        queryStr += ' AND ';
      }
      if (params.description) {
        queryStr += `UPDATE pomeranians SET description = '${params.description}' WHERE id = ${params.id}`;
      }
      queryStr += ';';
      db.query(queryStr, (err, results) => {
        if(err) {
          console.log('ERROR @ MOD-PUT: A pomeranian refuses to change...');
        } else {
          let selectQueryStr = `SELECT * FROM pomeranians WHERE id = ${params.id}`;
          db.query(selectQueryStr, function(err, results) {
            callback(err, results);
          });
        }
      });
    },
    delete: function (targeted, callback) {
      /*SQL STRING THAT DELETES SPECIFIED pomeranian*/
      let queryStr = `delete from pomeranians \
                      where id = ${targeted}`;
      db.query(queryStr, (err, results) => {
          callback(err, results);
      });
    }
  },
};
