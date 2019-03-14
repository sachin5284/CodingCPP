let x = [3,2,4,5,2,4,5,5,,4,32,2,3];
let dest ={};
Object.assign(dest,x);
//console.log(dest);
let y= x.reduce((a,b)=>a+b,0);
//console.log([...x]);

function makeWorker() {
    let name = "Pete";
  
    return function() {
      console.log(name);
    };
  }
  
  let name = "John";
  
  // create a function
  let work = makeWorker();
  
  // call it
  work();