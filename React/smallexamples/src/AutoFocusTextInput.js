import React,{Component} from 'react';

class AutoFocusTextInput extends Component {
    constructor(props)
    {
        super(props);
        this.state = {s:true};
        this.textInput = React.createRef();
    }

    handlerClicks = () =>
    {
        this.setState({s:!this.states});
        this.textInput.current.focus();
        console.log(this.textInput.current.AutoFocusTextInput);
    }
    render()
    {
        return (this.state.s &&
            <div>
                <input 
                    type ="text"
                    ref={this.textInput}/>
                <input 
                type="button"
                value="Focus the text input"
                onClick={this.handlerClicks}/>
            </div>
        );
    }
}


export default AutoFocusTextInput;