/* ┌──────────────────┬─────────────────────────────────────────────────────┬─────────────┐
   │ CARD             │ PREFIXES                                            │ LENGTHS     │
   ├──────────────────┼─────────────────────────────────────────────────────┼─────────────┤
   │ Diner's Club     │ 38, 39                                              │ 14          │
   │ American Express │ 34, 37                                              │ 15          │
   │ Visa             │ 4                                                   │ 13, 16, 19  │
   │ MasterCard       | 51, 52, 53, 54, 55                                  │ 16          │
   │ Discover         │ 6011, 644-649, 65                                   │ 16, 19      │
   │ Maestro          │ 5018, 5020, 5038, 6304                              │ 12-19       │
   │ China UnionPay   │ 622126-622925, 624-626, 6282-6288                   │ 16-19       │
   │ Switch           │ 4903, 4905, 4911, 4936, 564182, 633110, 6333, 6759  │ 16, 18, 19  │
   └──────────────────┴─────────────────────────────────────────────────────┴─────────────┘
*/

var fillRange = (start, end) =>
     [...Array(end - start + 1)].map((item, index) => start + index);

var createChinaUnionPayPrefixRegex = () => {
  var pArr = [].concat(
    fillRange(624, 626),
    fillRange(6282, 6288),
    fillRange(622126, 622925)
  )
  var pStr = '^' + JSON.stringify(pArr).replace(/,/g, '|').replace(/\[|\]/g, '');
  return new RegExp(pStr);
};

var initializeCardArray = () => {
  return [{type: 'China UnionPay', prefixes: createChinaUnionPayPrefixRegex(), lengths: /16|17|18|19/},
          {type: 'Diner\'s Club', prefixes: /^(38|39)/, lengths: /14/},
          {type: 'American Express', prefixes: /^(34|37)/, lengths: /15/},
          {type: 'MasterCard', prefixes: /^(51|52|53|54|55)/, lengths: /16/},
          {type: 'Discover', prefixes: /^(6011|644|645|646|647|648|649|65)/, lengths: /16|19/},
          {type: 'Maestro', prefixes: /^(5018|5020|5038|6304)/, lengths: /12|13|14|15|16|17|18|19/},
          {type: 'Switch', prefixes: /^(4903|4905|4911|4936|564182|633110|6333|6759)/, lengths: /16|18|19/},
          {type: 'Visa', prefixes: /^(4)/, lengths: /16|13|19/}];
};

var detectNetwork = function(cardNumber) {
  var len = cardNumber.length.toString();
  var creditCards = initializeCardArray();
  for (var card of creditCards) {
    if (card.prefixes.test(cardNumber) & card['lengths'].test(len)) {
      return card.type;
    }
  }
};
