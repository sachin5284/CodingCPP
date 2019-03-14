let john = { name: "John" };

let weakMap = new Map();
weakMap.set(john, "...");
console.log(weakMap.has(john));
john = null; // overwrite the reference
console.log(weakMap.entries());
// john is removed from memory!