import React, { Component } from 'react';
import MouseUpHook from './MouseUpHook';
import {Example} from './HooksExample';

class App extends Component {
  onEvent = e=>{
    console.log(e);
  }
  
  render() {
    return (
      <MouseUpHook onEvent={this.onEvent}>
        <Example/>
        <textarea>
          Hello there, this is some text in a text area
        </textarea>
      </MouseUpHook>
    );
  }
}


export default App;
