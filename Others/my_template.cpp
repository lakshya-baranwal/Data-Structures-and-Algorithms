// Aim for the most incredible goal your mind can conceive
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb push_back
#define eb emplace_back
#define up upper_bound
#define lb lower_bound
#define np next_permutation
#define mp make_pair

#define clr(x) memset(x, 0, sizeof(x))
#define setbits(a) (__builtin_popcountll(a)) // to count 1 bits 
#define right(a) (__builtin_ctzll(a)) // to count trailing 0s 
#define left(a) (__builtin_clzll(a)) // to count leading 0s 
#define parity(a) (__builtin_parityll(a)) // to check even odd
#define sz(a) ((int)a.size())
#define all(c) (c).begin(), (c).end()
#define allr(v) (v).rbegin(),(v).rend()
#define read(a) for(auto &it : a) cin>>it;
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define lb(x, v)  lower_bound(v.begin(), v.end(), x)      
#define ub(x, v)  upper_bound(v.begin(), v.end(), x)   
#define lbi(x, v) (lower_bound(v.begin(), v.end(), x) - v.begin()) // index of first >= x
#define ubi(x, v) (upper_bound(v.begin(), v.end(), x) - v.begin()) // index of first > x

#define inf 1e18
#define mod 1000000007
#define modd 998244353
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//*a.find_by_order() //a.order_of_key() //less //greater //less_equal

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

ll ceil_div(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b); }
ll fact[1001];
ll ifact[1001];
const int M =998244353;
ll power_mod( ll a , ll b, ll m = M) {
    if(b==0) return 1;
    ll x = power_mod(a,b/2); 
    if(b%2==0) return (x*x) % m; 
    else return ( ((x*x) % m) * a ) % m; 
}
ll mod_inv(ll a, ll m = M) { ll x = power_mod( a , m-2 ); return x; }
ll mod_add(ll &a, ll b, ll m = M){ return (a % m + b % m + m) % m; }
ll mod_sub(ll &a, ll b, ll m = M) { return (a % m - b % m + m) % m; }
ll mod_mul(ll &a, ll b, ll m = M) { return ((a % m) * (b % m)) % m; }
ll mod_div(ll &a, ll b, ll m = M) { return mod_mul(a, mod_inv(b, m)); }
ll nCr(ll n,ll r, ll m = M){
    return (((fact[n]*ifact[r])%m)*ifact[n-r])%m;
}
void factt(ll m = M){
   fact[0]=ifact[0]=1;
    for(ll i=1;i<=1000;i++){
        fact[i]=(i*fact[i-1])%m;
        ifact[i]=mod_inv(fact[i]);
   }
}


template <typename T>
void make_unique(vector<T> &v){sort(all(v));v.erase(unique(all(v)), v.end());}

template <typename T> void input (vector<T> &v,int n){v.resize(n);for(int i=0;i<n;i++){cin>>v[i];}}

/*======================================TEMPLATE-ENDS-HERE=============================================*/




void solve(){
    //code
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 

   int t; cin >> t;
   while(t--) solve();


  
 return 0; 
}
