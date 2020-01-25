var express = require('express');
var cors = require('cors')

var morgan = require('morgan');
var parser = require('body-parser');

var router = require('./routes.js');

var app = express();
module.exports.app = app;

app.use(cors())
app.set('port', 3000);

app.use(morgan('dev'));
app.use(parser.json());

app.use('/api/pomeranians', router);

app.listen(app.get('port'));
console.log('CORS-enabled web server listening on port', app.get('port'));
