var controller = require('./controllers');
var router = require('express').Router();

router.get('', controller.pomeranians.get);
router.post('', controller.pomeranians.post);
router.put('/:id', controller.pomeranians.put);
router.delete('/:id', controller.pomeranians.delete);

module.exports = router;
