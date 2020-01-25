const express = require('express');
const bodyParser = require('body-parser');
const db = require('../database');
const app = express();
const PORT = 3000;

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static(__dirname + '/../client/dist'));

app.all('/api/*', function(req, res, next) {
  res.header('Access-Control-Allow-Origin', '*');
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  res.header("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE");
  next();
});

app.get('/api/transactions', (req, res) => {
  db.getAllTransactions((err, results) => {
    if (err) {
      console.log('ERROR: Server failed to GET requested data.');
      res.sendStatus(500);
    }
    res.statusCode = 201;
    res.json(results);
  });
});

app.get('/api/subjects', (req, res) => {
  // db.getUsedSubjects((err, results) => {
  db.getAllSubjects((err, results) => {
    if (err) {
      console.log('ERROR: Server failed to GET requested data.');
      res.sendStatus(500);
    }
    res.statusCode = 201;
    res.json(results);
  });
});

app.post('/api/subjects', (req, res) => {
  var newSubject = [req.body.subject];
  db.addNewSubject(newSubject, (err, results) => {
    if (err) {
      console.log('ERROR: Subject failed to post.');
      res.sendStatus(500);
    }
    res.statusCode = 201;
    var body = [newSubject];
    res.send(body);
  });
});

app.put('/api/transactions', (req, res) => {
  var params = [req.body.subject, req.body.id];
  db.assignOrUpdateSubject(params, (err, results) => {
    if (err) {
      console.log('ERROR: Request to change subject failed.');
      res.sendStatus(500);
    }
    res.statusCode = 201;
    var body = [params[0], params[1]];
    res.send(body);
  });
});

app.listen(PORT, () => {
  console.log(`listening on port ${PORT}`);
});



