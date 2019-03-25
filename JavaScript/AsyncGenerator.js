async function* generateSequence(start,end)
{
    for(let i = start;i<end;i++)
    {
        await new Promise(resolve => setTimeout(resolve,1000));
        yield  i;
    }
}
var generator = generateSequence(1,5);

(async ()=>{
for await (let value of generator)
{
    console.log(value);
}
})();

(async () => {
    for await (let value of range)
    {
        console.log(value);
    }
})();

import {sayHi, sayBye} from './AsyncIterator.js';

sayHi('John'); // Hello, John!
sayBye('John'); // Bye, John!