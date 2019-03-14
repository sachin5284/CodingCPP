let variable ="sachin";
console.log("sachin");
//sachin(11);

let func = function sachin(v)
{    
    let hash= {};
    console.log(v);
    for(var i=1;i<v;i++)
    {
        hash[i]=true;
        console.log(i);
    }
};
func(11);
let str = "123";

console.log(typeof str); // string

let num = Number(str); // becomes a number 123

console.log(typeof num);

console.log(null == undefined)