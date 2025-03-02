//The least prime factor of an integer n is the smallest prime number that divides the number.
//The least prime factor of all even numbers is 2. A prime number is its own least prime factor (as well as its own greatest prime factor).
//Note: We need to print 1 for 1.
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define mod 1000000007
#define modd 998244353;

vector<int> least_prime(100001, 1);
void leastPrimeFactor() {
    //Computation of Least Prime Factor upto 1e5
    least_prime[0] = 0;
    for (int i = 2; i <= 100000; i++) {
        if (least_prime[i] == 1) {
            for (int j = i; j <= 100000; j += i)
                if (least_prime[j] == 1)
                    least_prime[j] = i;
        }
    }
}

void solve() {
    ll n; cin >> n;
    cout << n << " : " << least_prime[n] << "\n";
    //cout.flush();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    
    int t=1; cin >> t;
    leastPrimeFactor();
    while(t--) solve();
    return 0; 
}
