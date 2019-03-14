function User(name,birthday)
{   
    this._name = name;
    this._birthday = birthday;
};

User.prototype._calcAge = function()
{
    return new Date().getFullYear() - this._birthday.getFullYear();
};

User.prototype.sayHi = function()
{
    console.log(`${this._name},age: ${this._calcAge()}`);
};

let user = new User("John",new Date(2000,0,1));
user.sayHi();