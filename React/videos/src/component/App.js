import React,{Component} from 'react';
import youtube from '../apis/youtube';
import SearchBar from './SearchBar';
import VideoList from './VideoList';
import VideoDetails from './VideoDetail';

class App extends Component
{
    state ={videos:[],selectedVideo:null};

    componentDidMount()
    {
        this.onTermSubmit('cars');
    }

    onTermSubmit = async (term)=>{
       const result = await youtube.get('/search',{
            params:{
                q:term
            }
        });
        this.setState({videos:result.data.items})
        this.setState({selectedVideo:result.data.items[0]})
        //console.log(this.state.videos);
    };

    onVideoSelect = (video) => {
        this.setState({selectedVideo:video});
    }

    render(){
        return (
            <div className="ui Container">
                <SearchBar onFormSubmit={this.onTermSubmit}/>
                <div className="ui grid">
                <div className="ui row">
                    <div className="eleven wide column">
                        <VideoDetails selectedVideo={this.state.selectedVideo}/>
                    </div>
                    <div className="five wide columne">
                        <VideoList onVideoSelect={this.onVideoSelect} video={this.state.videos}/>
                    </div>
                </div>
                </div>
            </div>
        );
    }
};

export default App;