/*
  Uniq - higher order function that produces a
         duplicate-free version of the array.
*/
var uniq = function(array, isSorted = false, iterator = identity) {
  var identity = (val) => val;
  var tCollector = [];

  if (arguments[1].constructor === Function) {
    iterator = arguments[1];
    isSorted = false;
    console.log(typeof isSorted);
  }

  // FASTER ALGORITHM
  if (isSorted) {
    var collector = [array[0]];
    for (var i = 1; i < array.length; i++) {
      if (iterator(array[i-1]) !== iterator(array[i])) {
        collector.push(array[i]);
      }
    }
    return collector;
  }

  // SLOWER ALGORITHM
  return array.filter(function (oValue) {
    if (!tCollector.includes(iterator(oValue))) {
      tCollector.push(iterator(oValue));
      return oValue;
    }
  });
};

  let mySorted = [1, 1, 2, 2, 2, 3, 3, 3, 4, 4];
  let myIter = function(value) {
  return value === 3;
}
var output = uniq(mySorted, myIter);
console.log(output);


/***************************************************************
* dataType(val): uses Object.prototype and data type to return
*                data type of val.
*
*      CODE EXPLANATION
*         Object.prototype.toString.call(val)     ==>     [data type of 'val' as string]
*         .match(/(STUFF/g)                       ==>     [2nd word]
*         [0]                                     ==>     [from array returned by .match()]
*
*      PASSED IN                     RETURNED
*         [1, 2]                    ==> 'Array'
*         function() {return 'hi';} ==> 'Function'
*         null                      ==> 'Null'
*         1234567                   ==> 'Number'
*         {a: 1, b: 2}              ==> 'Object'
*         'hi'                      ==> 'String'
*         undefined                 ==> 'Undefined'
*
****************************************************************/

var dataType = function(val) {
  return Object.prototype.toString.call(val).match(/(?<=\s)\b\w*/g)[0];
};

