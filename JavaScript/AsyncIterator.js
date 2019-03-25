let range = {
    from:1,
    to:5,
    [Symbol.asyncIterator]()
    {
        return {
            current:this.from,
            last: this.to,
            async next()
            {
                await new Promise(resolve=>setTimeout(resolve,1000));
                if(this.current <= this.last){
                    return {done:false,value:this.current++};
                }
                else{
                    return {done:true};
                }
            }
        }
    }
};

function sayHi(user) {
    console.log(`Hello, ${user}!`);
  }
  
  function sayBye(user) {
    console.log(`Bye, ${user}!`);
  }
  
  export {sayHi, sayBye}; 