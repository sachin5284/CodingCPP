import {Component} from 'react';

class MouseUpHook extends Component {

    handleEvent = e => {
        this.props.onEvent(e);
    };

    componentDidMount=()=> {
        window.addEventListener("mouseup",this.handleEvent);
    };

    componentWillUnmount =() => {
        window.removeEventListener("mouseup",this.handleEvent);
    }

    render() {
        return this.props.children;
    }
};

export default MouseUpHook;

