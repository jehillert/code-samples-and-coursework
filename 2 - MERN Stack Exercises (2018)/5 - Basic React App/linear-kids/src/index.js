import React from 'react';
import ReactDOM from 'react-dom';
import App from './components/App'

ReactDOM.render(<App />, document.getElementById('app'));

/*
  ReactDOM.render(element, container[, callback])

    Render a React element into the DOM in the supplied container and
    return a reference to the component (or returns null for stateless components).

    If the React element was previously rendered into container, this will perform
    an update on it and only mutate the DOM as necessary to reflect the latest React element.

    If the optional callback is provided, it will be executed after the component
    is rendered or updated.
*/