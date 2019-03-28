import React from 'react';
import VideoItem from './VideoItem';

const VideoList = ({video,onVideoSelect}) =>{
    //props.video
    const renderedList =  video.map(v=> <VideoItem onVideoSelect={onVideoSelect} key={v.id.videoId} video={v}/>);
    return <div className="ui relaxed divided list">{renderedList}</div>
};

export default VideoList;

