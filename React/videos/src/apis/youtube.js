import axios from 'axios';

const KEY ='AIzaSyCDKhaMHgB0W-7ngKaHoNt8gUOf-mv__Gg';

export default axios.create({
    baseURL:"https://www.googleapis.com/youtube/v3",
    params:{
        part:'snippet',
        maxResults:5,
        key:KEY
    }
});