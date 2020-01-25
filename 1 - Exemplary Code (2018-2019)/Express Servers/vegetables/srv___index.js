const express = require('express');
const parser = require('body-parser');
const path = require('path');
const db = require('../db');
const app = express();
const port = 3000;

app.use(parser.json());
app.use(parser.urlencoded({extended: false}));

app.get('/', function(req, res){
  res.sendFile(path.join(__dirname + '/index.html'));
});

app.get('/api/vegetables/', (req, res) => {
  db.getVegetableList((err, results) => {
    if (err) {
      console.log(`ERROR: 'GET' request failed to retrieve vegetable list`);
      res.sendStatus(500);
    } else {
      res.statusCode = 201;
      res.json(results);
    }
  });
});

app.post('/api/vegetables/', (req, res) => {
  db.addFoodItem(req.body.food, req.body.quantity, (err, results) => {
    if (err) {
      res.sendStatus(500);
      console.log(`ERROR: 'POST' request failed to add food item to vegetable list`);
    } else {
      console.log(`Added ${req.body.quantity} ${req.body.food} to vegetable list.`)
      res.statusCode = 201;
      res.send(req.body);
    }
  });
});

app.listen(port, () => console.log(`\n\n\n\nlistening on port ${port}...
\n...Si qui que ce soit puisse entendre ceci, ils sont morts.
Veuillez nous aider. Je vais essayer d'aller jusqu'au
Rocher Noir. Il les a tués. Il les a tués tous...
\n...Il est dehors. il est dehors et Brennan a pris les clés.
Veuillez nous aider. Ils sont morts. Ils sont tous morts.
Aidez-nous. Ils sont morts...
\n...Il est dehors. Il est dehors et Brennan a pris les clés.
Veuillez nous aider. Ils sont morts. Ils sont tous morts.
Aidez-nous. Ils sont morts...
\n...Ils sont tous morts. Aidez-nous. Ils sont morts. Si qui
que ce soit puisse entendre ceci...
\n...Il est dehors. Veuillez nous aider. Veuillez nous aider.
\n...Si qui que ce soit puisse entendre ceci, je vais essayer
d'aller jusqu'au Rocher Noir. Veuillez nous aider. Ils
sont tous morts. Ils sont morts. Il les a tués. Ils les a
tués tous. Je vais essayer d'aller jusqu'au Rocher Noir.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n`));
