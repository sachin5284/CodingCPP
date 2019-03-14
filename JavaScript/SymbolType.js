let user = {
    name: "John",
    money: 1000,
  
    // for hint="string"
    toString() {
      return `{name: "${this.name}"}`;
    },
  
    // for hint="number" or "default"
    valueOf() {
      return this.money;
    },
    sayhi(s)
  {
      console.log(s);
  }
  };

  user.sayhi("ss");
  // conversions demo:
  console.log(user.toString()); // hint: string -> {name: "John"}
  console.log(+user); // hint: number -> 1000
  console.log(user + 500); // hint: default -> 1500
  let secondUser = user;
  user= null;
  console.log(secondUser);