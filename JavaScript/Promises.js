let promise = new Promise((resolve, reject) => {
    // not taking our time to do the job
    resolve("123"); // immediately give the result: 123
  });

  promise.then(console.log);

  class Thenable {
    constructor(num) {
      this.num = num;
    }
    then(resolve, reject) {
      console.log(resolve); // function() { native code }
      // resolve with this.num*2 after the 1 second
      setTimeout(() => resolve(this.num * 2), 1000); // (**)
    }
  }
  
  new Promise(resolve => resolve(1))
    .then(result => {
      return new Thenable(result); // (*)
    })
    .then(console.log); // shows 2 after 1000ms

    
    fetch(`https://api.github.com/users/iliakan`)
    // Load the response as json
    .then(response => response.json())
    // Show the avatar image (githubUser.avatar_url) for 3 seconds (maybe animate it)
    .then(githubUser => {
      let img = document.createElement('img');
      img.src = githubUser.avatar_url;
      img.className = "promise-avatar-example";
      document.body.append(img);
  
      setTimeout(() => img.remove(), 3000); // (*)
    });
    let a= [1,2];
    a.m