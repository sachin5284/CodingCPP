import axios from 'axios';

export default axios.create({
    baseURL:'https://api.unsplash.com',
    headers:{
        Authorization : 
        'Client-ID 40244b0654aa3da25d5071431b1a6ba7528500b9b41112a7e50bbbfa8e75d768'
    }
});