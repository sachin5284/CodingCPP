let User = function (name)
{
    if(!new.target)
        return new User(name);
    this.name = name;
    this.age = 21;
}

let user =  User("sachin");
console.log(user);