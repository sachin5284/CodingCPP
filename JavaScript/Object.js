// let user = new Object();
// let secondUser = user;
// user.name="sachin";
// console.log(user,secondUser);
// var assign={};
// Object.assign(assign,user,secondUser);
// console.log(assign);

let user ={
    name:"John",
    surname:"Smith"
};
console.log(user);
user.name="Pete";
console.log(user);
delete user.name;
console.log(user);
console.log(isEmpty(user));

function isEmpty(user)
{
    for(let element in user)
    {
        return false;
    }
    return true;
}