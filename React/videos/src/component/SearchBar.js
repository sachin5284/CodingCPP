import React from 'react';

class SearchBar extends React.Component {
    constructor(props)
    {
        super(props);
        this.state = {input:''};
    }

    onFormSubmit= (event) => {
        event.preventDefault();
        this.props.onFormSubmit(this.state.input);
        //Todo: Make sure we call callback from parent component
    };

    setInputChange= (e) => {
        this.setState({input:e.target.value});
    };
    render()
    {
        return (
            <div className="search-bar ui segment">
                <form className="ui form" onSubmit={this.onFormSubmit}>
                    <div className="field">
                        <label>Video Search</label>
                        <input 
                            type="text" 
                            name="name" 
                            value={this.state.input} 
                            onChange={this.setInputChange}
                        />
                    </div>
                </form>
            </div>
        );
    }
};

export default SearchBar;