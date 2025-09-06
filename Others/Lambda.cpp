//Lambda functions can be quite useful while doing custom sorting. 
//They also enable functional programming by passing simple logic as arguments.

//First Example -> Simple lambda function
int a, b;
cin >> a >> b;

auto lambda = [](int x, int y) -> int {
   return x + y;
};

cout << lambda(x, y) << endl;

//Second Example -> Recursive lambda function
int a; 
cin >> a;

function<void(int)> series = [&](int x){
   if(x == 1) {
     cout << x << endl;
     return;
   }
   
   cout << x << endl;
   series(x-1);
};

//Recursive Lambda Example 
int n; cin >> n;

    auto fib = [&](auto &&self, int n)->long long{
        if(n <= 1) return n;
        else return self(self, n-1) + self(self, n-2);
    };
 cout << fib(fib, 15) << endl;

//Use of lambda function in custom sorting
//Custom sorting used in vector<vector<string>> events
auto lambda = [&](vector<string> s1, vector<string> s2){
            //if(s1[0] == s2[0]) return true;
            int a = fetch_time(s1[1]);
            int b = fetch_time(s2[1]);
            if(a != b){
                return a < b;
            }
            
            return s1[0] > s2[0];
          
        };
sort(begin(events), end(events), lambda);

// Using lambda function for calculating subtree size 
function<void(int, int)> dfs = [&](int u, int p) -> void {
    sz[u] = 1;
        
    for(auto v: adj[u]){
     if(v == p) continue;
         dfs(v, u);
         sz[u] += sz[v];
    }
};
dfs1(0, -1);


// Using lambda function to find centroid of a tree
function<int(int, int, int)> find_centroid = [&](int u, int p, int n) -> int {
        
        for(auto v: adj[u]){
            if(v == p) continue;
            if(sz[v] > n/2) return find_centroid(v, u, n);
        }
        return u;
    };

    
