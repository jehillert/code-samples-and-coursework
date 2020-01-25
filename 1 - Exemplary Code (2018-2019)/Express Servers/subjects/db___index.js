const mysql = require(`mysql`);
const mysqlConfig = require(`./config.js`);

const connection = mysql.createConnection(mysqlConfig);

const addNewSubject = function(newSubject, callback) {
  var queryStr = `INSERT IGNORE INTO subjects(subject) VALUE (?)`;
  connection.query(queryStr, newSubject, function(err, results) {
    callback(err, results);
  });
};

const assignOrUpdateSubject = function(params, callback) {
  var queryStr = `UPDATE transactions
                  SET
                    subject_id = (
                      SELECT
                        subject_id
                      FROM
                        subjects
                      WHERE
                        subject = ?
                    )
                  WHERE
                    id = ?`;
  connection.query(queryStr, params, function(err, results) {
    callback(err, results);
  });
};

const getUsedSubjects = function(callback) {
  var queryStr = `SELECT subject FROM transactions
                  LEFT JOIN subjects USING (subject_id)
                  WHERE subject IS NOT NULL
                  GROUP BY subject HAVING COUNT(*) > 0
                  ORDER BY COUNT(*) DESC`;
  connection.query(queryStr, function(err, results) {
    callback(err, results);
  });
};

const getUnusedSubjects = function(callback) {
  var queryStr = `SELECT t2.subject FROM transactions t1
                  RIGHT OUTER JOIN subjects t2
                  ON t1.subject_id = t2.subject_id
                  WHERE t1.subject_id IS NULL
                  ORDER BY subject ASC`;
  connection.query(queryStr, function(err, results) {
    callback(err, results);
  });
};

const getAllSubjects = function(callback) {
  var queryStr = `SELECT * FROM subjects
                    ORDER BY subject_id`;
  // var queryStr = `Select *
  //                 from (
  //                   ( SELECT subject, COUNT(subject) FROM transactions
  //                     LEFT JOIN subjects USING (subject_id)
  //                     WHERE subject != ''
  //                     GROUP BY subject HAVING COUNT(*) > 0)
  //                   UNION ALL
  //                   ( SELECT t2.subject, COUNT(t2.subject) FROM transactions t1
  //                     RIGHT OUTER JOIN subjects t2
  //                     ON t1.subject_id = t2.subject_id
  //                     WHERE t1.subject_id IS NULL
  //                     GROUP BY subject HAVING COUNT(*) > 0 )
  //                 ) as stuff`;
  connection.query(queryStr, function(err, results) {
    callback(err, results);
  });
};

const getAllTransactions = function(callback) {
  var queryStr = `SELECT * FROM transactions LEFT JOIN subjects USING (subject_id)`;
  connection.query(queryStr, function(err, results) {
    callback(err, results);
  });
};

module.exports = {
  addNewSubject,
  assignOrUpdateSubject,
  getUsedSubjects,
  getUnusedSubjects,
  getAllSubjects,
  getAllTransactions
};
