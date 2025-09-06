/*
    -----------------------------------
    Small-to-Large Merging on Trees
    -----------------------------------
    Idea:
        While processing a tree with DFS, we need to maintain some 
        information for each subtree. If we naively merge child data 
        into parent, it can be O(n^2). 
        Instead, we always merge the smaller container into the larger one.
        This guarantees each element is moved O(log n) times, making 
        the total complexity ~ O(n log^2 n).

    Implementation:
        For each node u:
            - Start with its own contribution (a[u]).
            - DFS into children.
            - Merge child dp[v] into dp[u] (swapping so we always merge
              small into large).
            - Store result for this node (e.g., number of distinct values)."

    Complexity:
        O(n log^2 n) with std::map / std::set
        O(n log n) expected with unordered_map

    --------------------
    Applications:
    --------------------
    1. Count distinct values in each subtree.
    2. Maintain frequency of colors/numbers in subtrees.
    3. DSU on tree (aka Sack technique) when queries depend on 
       subtree aggregations.
    4. Any problem where merging subtrees' data is required but 
       direct O(n^2) merging would be too slow.
*/

void slm(int n, vector<int>& a, vector<vector<int>>& adj, vector<int>& ans) {
    vector<unordered_map<int,int>> dp(n+1);

    function<void(int,int)> dfs = [&](int u, int p) {
        dp[u][a[u]]++; // add own value

        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs(v,u);

            // merge smaller map into larger map
            if (dp[v].size() > dp[u].size()) swap(dp[u], dp[v]);

            for (auto &kv : dp[v]) {
                dp[u][kv.first] += kv.second;
            }
            dp[v].clear(); // free memory
        }

        ans[u] = dp[u].size(); // store distinct count for node u
    };

    dfs(1,-1);
}
