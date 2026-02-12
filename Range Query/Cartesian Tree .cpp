// Cartesian Tree

// Important properties:
//  Min-Heap Property 
//  Inorder traversal of the tree gives back the original order
//  LCA(i,j) = argmin(a[i..j])

// Each node stores: 
//  G[i].left   = index of left child
//  G[i].right  = index of right child
//  G[i].parent = parent

// we can do minor changes to convert min heap to max heap
typedef pair<int, int> P;

struct CartesianTree {
  struct Node {
    int left, right, parent;
    Node(){ left = -1, right = -1, parent = -1; }
    Node(int l, int r, int p){ left = l, right = r, parent = p; }
  };

  int root;
  vector<Node> G;

  CartesianTree(){}
  CartesianTree(vector<int> a, int n){ init(a, n); }

  int init(vector<int> a, int n) {
    // G[1..n] is an cartesian tree for input a[1..n]; return the ID of root
    vector<int> lvec(n+1), rvec(n+1);

    stack<P> stk;
    stk.push(P(-inf, 0)); // change sentinel to +inf for max heap
    
    for(int i = 1; i <= n; i++){
      // change > to < for max heap
      while(stk.top().first > a[i]) stk.pop();
      lvec[i] = stk.top().second;
      stk.push(P(a[i], i));
    }
    while(stk.size()) stk.pop();

    stk.push(P(-inf, n+1));
    for(int i = n; i >= 1; i--){
      // change >= to <= for max heap
      while(stk.top().first >= a[i]) stk.pop();
      rvec[i] = stk.top().second;
      stk.push(P(a[i], i));
    }

    G.clear();
    G.resize(n+1);
    
    for(int i = 1; i <= n; i++){
      // initialize local bounds to +inf
      int l = -inf, r = -inf;
      if(lvec[i] >= 1) l = a[lvec[i]];
      if(rvec[i] <= n) r = a[rvec[i]];
      if(lvec[i] < 1 and rvec[i] > n) {
        G[i].parent = -1, root = i;
        continue;
      }
      // change > to < for max heap
      // why change: choose the smaller neighbour as a parent
      // because in max heap, smaller values are deeper/closer to children
      if(l > r) G[lvec[i]].right = i, G[i].parent = lvec[i];
      else G[rvec[i]].left = i, G[i].parent = rvec[i];
    }
    return root;
  }
};
