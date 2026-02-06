struct BinaryLifting {
    int n, LOG;
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;

    BinaryLifting(int n_){ init(n_); }

    void init(int n_){
        n = n_;
        LOG = 1;
        while((1 << LOG) <= n) ++LOG;

        up.assign(n+1, vector<int>(LOG, 0));
        depth.assign(n+1, 0);
        adj.assign(n+1, {});
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p){
        up[u][0] = p;

        for(int v : adj[u]){
            if(v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    void build(int root = 1){
        dfs(root, 0);

        for(int j = 1; j < LOG; j++){
            for(int v = 1; v <= n; v++){
                int mid = up[v][j-1];
                up[v][j] = mid ? up[mid][j-1] : 0;
            }
        }
    }

    // jump k ancestors up
    int lift(int u, int k){
        for(int j = 0; j < LOG && u; j++){
            if(k & (1<<j)){
                u = up[u][j];
            }
        }
        return u;
    }

    int lca(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);

        u = lift(u, depth[u] - depth[v]);

        if(u == v) return u;

        for(int j = LOG-1; j >= 0; j--){
            if(up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    int dist(int u, int v){
        int w = lca(u, v);
        return depth[u] + depth[v] - 2*depth[w];
    }
};
