// Linear Sieve for Prime Generation and Smallest Prime Factor (SPF)

// Notation : minp[i] -> smallest prime factor of i
// Using some of the following properties:
 // 1. Each composite number is marked exactly once
 // 2. Time complexity is O(n)


//CODE
  vector<int> minp, primes;
 
  void sieve(int n){
      minp.assign(n + 1, 0);
      primes.clear();
      
      for(int i = 2; i <= n; i++){
          if(minp[i] == 0){
              minp[i] = i;
              primes.push_back(i);
          }
          
          for(auto p : primes){
              if(1LL * i * p > n) break;
              minp[i * p] = p;
              if(p == minp[i]) break;
          }
      }
  }
