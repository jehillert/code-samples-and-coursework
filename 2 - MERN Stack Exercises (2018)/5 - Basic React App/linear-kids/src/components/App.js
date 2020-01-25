import React from 'react';
import AGrandParentAParentAndUnfortunatelyFourKids from './AParent';
import SomebodyElsesGrandfather from './AGrandfather';

class App extends React.Component {
  render() {
    {
      var farEnough = 20;
      var AShufflingAway = [];
      for (var feetFromSafety = 0; feetFromSafety <= farEnough; feetFromSafety++) {
        AShufflingAway.push(<br></br>);
      }
    }
    return (
      <div id="app">
        <div><AGrandParentAParentAndUnfortunatelyFourKids /></div>
        {AShufflingAway}
        <div><SomebodyElsesGrandfather />And I find children in linear arrangements to be creepy...</div>
      </div>
      )
    }
  }
export default App;