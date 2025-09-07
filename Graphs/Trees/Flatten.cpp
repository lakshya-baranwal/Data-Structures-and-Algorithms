// Euler's Tour
struct Flatten {
    vector<vector<int>> adj;
    vector<int> tin, tout, euler;
    int timer;

    Flatten(int n) {
        adj.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        timer = 0;
    }

    void add_edge(int u, int v) {
        --u; --v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void work() {
        timer = 0;
        euler.clear();
        dfs(0, -1);
    }

    void dfs(int u, int p) {
        tin[u] = timer;
        euler.push_back(u);
        timer++;
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
        tout[u] = timer;
    }
    inline int subtree_size(int u) const {
        return tout[u] - tin[u];
    }

    // subtree of u = [tin[u], tout[u])
    // nodes: euler[tin[u] ... tout[u]-1]
};
