// Binary Lifting on Functional Graphs
// Each node has exactly only one outgoing edge
// May contain cycles 

struct Doubling {
  int n = 0;
  static const int LOG = 18;
  vector<vector<int>> nxt; // nxt[d][i] = node after 2 ^ d steps
  vector<vector<int>> val; // val[d][i] = aggregate over 2 ^ d steps
  
  Doubling(const vector<int>& g, const vector<int>& w) {
      n = g.size();

      nxt.assign(LOG, vector<int> (n));
      val.assign(LOG, vector<int> (n));

      for(int i = 0; i < n; i++) {
          nxt[0][i] = g[i];
          val[0][i] = w[i];
      }

      for(int d = 1; d < LOG; d++) {
          for(int i = 0; i < n; i++) {
              int j = nxt[d - 1][i];

              nxt[d][i] = nxt[d - 1][j];
              val[d][i] = val[d - 1][i] + val[d - 1][j];
          }
      }
  }
  
  int jump(int i, int k) {
      for(int d = 0; d < LOG; d++) {
          if(k & (1LL << d)) {
              i = nxt[d][i];
          }
      }
      return i;
  }
  
  int query(int i, int k) {
      int ans = 0;

      for(int d = 0; d < LOG; d++) {
          if(k & (1LL << d)) {
              ans += val[d][i];
              i = nxt[d][i];
          }
      }
      return ans;
  }
};
