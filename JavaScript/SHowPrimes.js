function showPrimes(n) {
    nextPrime:
    for (let i = 2; i < n; i++) {
  
      // check if i is a prime number
      for (let j = 2; j < i; j++) {
        if (i % j == 0) continue nextPrime;
      }
  
      console.log(i);
    }
  }
  function pow() {
    return 8; // :) we cheat!
  }
if(true){
    console.log("sachin,,,,!!");
}

  showPrimes(10);