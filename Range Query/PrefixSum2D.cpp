#include <bits/stdc++.h>
using namespace std;

/*
    -----------------------------------
    2D Prefix Sum (1-based Indexing)
    -----------------------------------
    pre[i][j] = sum of all elements v[x][y] 
                where 1 <= x <= i and 1 <= y <= j

    Precomputation:
        pre[i][j] = v[i][j] 
                    + pre[i-1][j] 
                    + pre[i][j-1] 
                    - pre[i-1][j-1]

    Query:
        sum of submatrix from (a,b) to (c,d):
        sum = pre[c][d] 
              - pre[a-1][d] 
              - pre[c][b-1] 
              + pre[a-1][b-1]

    Complexity:
        Precomputation: O(n*m)
        Query: O(1)
*/

// Build prefix sum array (1-based indexing)
vector<vector<long long>> buildPrefix2D(const vector<vector<long long>>& v) {
    int n = v.size() - 1; // assuming v[1..n][1..m]
    int m = v[0].size() - 1;
    vector<vector<long long>> pre(n+1, vector<long long>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = v[i][j] 
                      + pre[i-1][j] 
                      + pre[i][j-1] 
                      - pre[i-1][j-1];
        }
    }
    return pre;
}

// Query sum from (a,b) to (c,d) inclusive
long long query2D(const vector<vector<long long>>& pre, int a, int b, int c, int d) {
    return pre[c][d] 
         - pre[a-1][d] 
         - pre[c][b-1] 
         + pre[a-1][b-1];
}
