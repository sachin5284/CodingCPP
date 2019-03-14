// Same Animal as before
function Animal(name) {
    this.names = name;
  }
  
  // All animals can eat, right?
  Animal.prototype.eat = function() {
    console.log(`${this.names} eats.`);
  };
  
  // Same Rabbit as before
  function Rabbit(name) {
    this.name = name;
  }
  
  Rabbit.prototype.jump = function() {
    console.log(`${this.name} jumps!`);
  };
  
  // setup the inheritance chain
  Rabbit.prototype.__proto__ = Animal.prototype; // (*)
  
  let rabbit = new Rabbit("White Rabbit");
  rabbit.eat(); // rabbits can eat too
  rabbit.jump();


  class User
  {
      constructor(name)
      {
        this.name = name;
      }
      sayHi()
      {
          console.log(this.name);
      }
  };

  class ChildUser extends User{
      constructor(name,childname)
      {
          super(name);
          this.childname = childname;
      }

      sayHi()
      {
          super.sayHi();
          console.log(this.childname);
      }
  }

  new ChildUser("USER","ChildUSER").sayHi();


  let animals = {
    name: "Animal",
    eat() {
      console.log(`${this.name} eats.`);
    }
  };
  
  let rabbits = {
    __proto__: animals,
    eat() {
      // ...bounce around rabbit-style and call parent (animal) method
      this.__proto__.eat.call(this); // (*)
    }
  };
  
  let longEar = {
    __proto__: rabbits,
    eat() {
        
      // ...do something with long ears and call parent (rabbit) method
      this.__proto__.eat.call(this); // (**)
    }
  };
  
  longEar.eat();