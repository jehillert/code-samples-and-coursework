var models = require('./models');

module.exports = {

  pomeranians: {
    get: function (req, res) {
      models.pomeranians.get(function(err, results) {
        if(err) {
          console.log('ERROR @ CTRL-GET: A pomeranian has no name...');
          res.sendStatus(500);
        }
        res.json(results);
      });
    },
    post: function (req, res) {
      var params = [req.body.name, req.body.description];
      models.pomeranians.post(params, function(err, results) {
        if (err) {
          console.log('ERROR @ CTRL-POST: Still the pomeranian has no name.');
          res.sendStatus(500);
        } else {
          res.statusCode = 201;
          var body = req.body;
          res.send(body);
        }
      });
    },
    put: function (req, res) {
      req.body.id = req.params.id;
      models.pomeranians.put(req.body, (err, results) => {
        if(err) {
          console.log('ERROR @ CTRL-PUT: A pomeranian has no hobbies...');
          res.sendStatus(500);
        }
        res.json(results);
      });
    },
    delete: function (req, res) {
      models.pomeranians.delete(req.params.id, function(err, results) {
        if (err) {
          console.log('ERROR @ CTRL-DELETE: The pomeranian continues to be...');
          res.sendStatus(500);
        } else {
          res.sendStatus(201);
        }
      });
    }
  }
};
