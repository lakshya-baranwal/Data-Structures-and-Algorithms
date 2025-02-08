//Euler's Totient Function in O(sqrt(N))

 //Notation : phi(n)
 //Using some of the following properties:
  //1. phi(p) = p-1, where p is a prime number
  //2. phi(n) is multiplicative
  //3. phi(power(p, x)) = power(p, x-1) * (p-1), where p is a prime number       
            

//CODE

  int phi(int n){
      int res = n;
      
      for(int i = 2; i*i <= n; i++){
          if(n%i == 0){
              res /= (i);
              res *= (i-1); 
          }
          while(n%i == 0){
              n /= i;
          }
      }

      if(n > 1){
          res /= n;
          res *= (n-1);
      }

      return res;
  }
