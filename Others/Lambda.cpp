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
