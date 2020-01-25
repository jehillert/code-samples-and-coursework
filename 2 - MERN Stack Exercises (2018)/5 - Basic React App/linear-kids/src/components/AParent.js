import React from 'react';
import SomeDude from './AGrandfather'

class AParent extends React.Component {

  constructor() {
    super();
    this.kids = ['1st kid', '2nd kid', '3nd kid', '4th kid']
  }

  printKidsOneDay() {
      var kidsInOrder = this.kids.map(function(kid) {
        return <div>{kid} . . . one who whines about inline lines . . .</div>;
      })
      return  <ul>{ kidsInOrder }</ul>
    }

  render() {
    return (
      <div>
        <SomeDude />
        { this.printKidsOneDay() }
      </div>
    )
  }
}

export default AParent;
