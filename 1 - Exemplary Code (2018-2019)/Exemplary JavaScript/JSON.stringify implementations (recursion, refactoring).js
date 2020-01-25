/***********************************************************
* ABOUT THIS FILE
************************************************************/
// One of Hack Reactor's Pair Programming excercises asked
// us to come up with our own recursive implementation of
// JSON.stringify. This file shows the solution my partner
// and I came up with And two alternative implementations I
// coded by myself.

/***********************************************************
* SOLUTION 1: Done with a partner (Pair-Programming)
************************************************************/
// --- Pseudo-Code/Outline ---
// if object or array
// if array
//   for...of loop
//     item is object
//       str += '{' + stringifyJSON(item).slice(0, -1) + '}';
//       1, 2, 3,   ===>   1, 2, 3 ===>  {1, 2, 3}
//     item is array
//       str += '[' + stringifyJSON(item).slice(0, -1) + ']';
//       1, 2, 3,   ===>   1, 2, 3 ===>  [1, 2, 3]
//     else
//       str += primToStr
// else (its an object)
//   for...in loop
//     item is object
//       str += '{' + stringifyJSON(item).slice(0, -1) + '}';
//     item is array
//       str += '[' + stringifyJSON(item).slice(0, -1) + ']';
//     else
//       str += primToStr
// else
//   str += primToStr()
// return str
// End of Function

var stringifyJSON = function(obj) {
  var str = '';

  if (Object.prototype.toString.call(obj) === "[object Object]" || Array.isArray(obj)) {
    if (Array.isArray(obj)) {
      str += '['

      for (var item of obj) {
        if (Object.prototype.toString.call(obj) === "[object Object]") {
          if (item !== undefined && typeof item !== 'function') { // skip if undefined or a function
            str += stringifyJSON(item);
            str += ','
          }
        } else if (Array.isArray(obj)) {
          if (item !== undefined && typeof item !== 'function') { // skip if undefined or a function
            str += stringifyJSON(item);
            str += ','
          }
        } else {
          if (obj[key] !== undefined || Object.prototype.toString.call(obj[key]) !== "[object Function]") {
            if (item !== undefined && typeof item !== 'function') { // skip if undefined or a function
              str += primToStr(obj);
              str += ','
            }
          }
        }
      }

      str += '],';
    } else if (Object.prototype.toString.call(obj) === "[object Object]") {
        str += '{';
        for (var key in obj) {
          if (Object.prototype.toString.call(obj) === "[object Object]") {
            if (obj[key] !== undefined && typeof obj[key] !== 'function') { // skip if undefined or a function
              str += primToStr(key) + ':' + stringifyJSON(obj[key]);
              str += ','
            }
          } else if (Array.isArray(obj[key])) {
            if (obj[key] !== undefined && typeof obj[key] !== 'function') { // skip if undefined or a function
              str += primToStr(key) + ':' + stringifyJSON(obj[key]);
              str += ','
            }
          } else {
            if (obj[key] !== undefined && typeof obj[key] !== 'function') { // skip if undefined or a function
              str += primToStr(key) + ':' + primToStr(obj[key]);
              str += ','
            }
          }
        }

        str += '},';
    }
  } else {
    str += primToStr(obj);
  }

  str = str.replace(/(,)(]|\})/gi, '$2');
  str = str.replace(/,(?=$)/gi, '');

  return str;

  function primToStr(p) {
    if (typeof p === 'string') {
      return '\"' + p + '\"';
    }

    return p;
  }

};

/***********************************************************
* SOLUTION 2: Solo Refactoring of 1st Solution
************************************************************/
// --- Pseudo-Code/Outline ---
// if object or array
//   if array
//     for...of loop
//       item is object
//         str += '{' + stringifyJSON(item).slice(0, -1) + '}';
//         1, 2, 3,   ===>   1, 2, 3 ===>  {1, 2, 3}
//       item is array
//         str += '[' + stringifyJSON(item).slice(0, -1) + ']';
//         1, 2, 3,   ===>   1, 2, 3 ===>  [1, 2, 3]
//       else
//         str += primToStr
//   else (its an object)
//     for...in loop
//       item is object
//         str += '{' + stringifyJSON(item).slice(0, -1) + '}';
//       item is array
//         str += '[' + stringifyJSON(item).slice(0, -1) + ']';
//       else
//         str += primToStr
//   else
//     str += primToStr()
//   return str

var stringifyJSON = function(obj) {
  //MAIN FUNCTION
  var str = '';

  if (dataType(obj) === 'Array') {
    str += '[' + arrContents(obj) + '],';
  } else if (dataType(obj) === 'Object') {
    str += '{' + objContents(obj) + '},';
  } else {
    str += strfyPrim(obj);
  }

  return removeExtraneousCommas(str);

  // HELPER FUNCTIONS
  function addArrItem(item) {
    return (typeof item === 'object') ? stringifyJSON(item) + ','
         : (typeof item !== 'function' && item !== undefined) ? strfyPrim(item) + ',' : '';
  }

  function addObjItem(item, key) {
    return (typeof item === 'object') ? strfyPrim(key) + ':' + stringifyJSON(item) + ','
         : (typeof item !== 'function' && item !== undefined)  ? strfyPrim(key) + ':' + strfyPrim(item) + ',' : '';
  }

  function arrContents(obj) {
    return obj.reduce(function(contents, item, index, obj) {
        return contents + addArrItem(item);
    }, '');
  }

  function dataType(val) {
    return Object.prototype.toString.call(val).match(/(?<=\s)\b\w*/g)[0];
  }

  function objContents(obj) {
      var contents = '';
      for (var key in obj) {
        contents += addObjItem(obj[key], key);
      }
      return contents;
  }

  function removeExtraneousCommas(str) {
    return str.replace(/(,)(]|\})/gi, '$2').replace(/,(?=$)/gi, '');
  }

  function strfyPrim(p) {
    return ( typeof p === 'string' ) ? ( '\"' + p + '\"' ) : ( p );
  }
};

/********************************************
* SOLUTION 3: Another implementation
*********************************************/
var stringifyJSON = function(obj) {
  var results = '';
  if ( obj === null ) {
    return 'null';
  }
  if (typeof obj === 'string') {
    return results = '"' + obj + '"';
  }
  if (Array.isArray(obj)) {
    results = [];
    for (var item of obj) {
      results.push(stringifyJSON(item));  //
    }
    return '[' + results.join() + ']';
  }
  if (typeof obj === 'object') {
    results = [];
    for (var key in obj) {
      if (typeof obj[key] === 'function' || obj[key] === undefined) {
        continue;
      }
      results.push(stringifyJSON(key) + ':' + stringifyJSON(obj[key])); //delete comma?
    }
    return '{' + results.join() + '}'; //{[1, 2, 3]}
  }

  return results + obj; //case for bool null and num
};
