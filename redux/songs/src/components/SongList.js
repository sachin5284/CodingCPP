import React,{Component} from 'react';
import {connect} from 'react-redux';
import {selectSong} from '../actions';


class SongList extends Component{
    
    renderList=()=> {
        return this.props.songs.map((song)=> {
            return (
                <div className="item" key={song.title}>
                    <div className="right floated content">
                        <button className="ui button primary" 
                        onClick={()=>this.props.selectSong(song)}>
                            Select
                        </button>   
                    </div>
                    <div classsName="content">{song.title}</div>
                </div>
            );
        });
    };

    render(){
        
        return <div className="ui divided list">{this.renderList()} </div>;
    }
};

const mapStateToProps =(state) =>{
    console.log(state.selectedSong);
    return {songs:state.songs,
    SongList:state.selectedSong};
}

export default connect(mapStateToProps ,{selectSong})(SongList);