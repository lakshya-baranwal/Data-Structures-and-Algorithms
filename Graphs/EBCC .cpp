struct EBCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk, dfn, low, bel, isCut;
    vector<pair<int,int>> br; // list of bridges
    int cur, cnt;

    EBCC() {}
    EBCC(int n) { init(n); }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.assign(n, 0);
        bel.assign(n, -1);
        isCut.assign(n, 0);
        stk.clear();
        br.clear();
        cur = cnt = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Tarjan’s DFS in O(n + m)
    void dfs(int u, int p) {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        int child = 0;

        for (auto v : adj[u]) {
            if (v == p) continue;
            if (dfn[v] == -1) {
                child++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                // articulation condition (non-root)
                if (p != -1 && low[v] >= dfn[u]) {
                    isCut[u] = 1;
                }

                // bridge condition
                if (low[v] > dfn[u]) {
                    br.emplace_back(u, v);
                }
            } else if (bel[v] == -1) {
                low[u] = min(low[u], dfn[v]);
            }
        }

        // articulation condition (root)
        if (p == -1 && child > 1) {
            isCut[u] = 1;
        }

        // extract one biconnected component
        if (dfn[u] == low[u]) {
            while (true) {
                int x = stk.back();
                stk.pop_back();
                bel[x] = cnt;
                if (x == u) break;
            }
            cnt++;
        }
    }

    // Run Tarjan’s algorithm in O(n + m)
    void work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i, -1);
            }
        }
    }

    // List of articulation points in O(n)
    vector<int> articulationPoints() {
        vector<int> res;
        for (int i = 0; i < n; i++) if (isCut[i]) res.push_back(i);
        return res;
    }

    // List of bridges in O(m)
    vector<pair<int,int>> bridges() {
        return br;
    }

    // Compressed bridge-tree (block-cut tree) in O(n + m)
    struct Graph {
        int n;
        vector<pair<int,int>> edges;
        vector<int> siz;  // size of each component
        vector<int> cnte; // count of inner edges
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.assign(cnt, 0);
        g.cnte.assign(cnt, 0);

        for (int u = 0; u < n; u++) {
            g.siz[bel[u]]++;
            for (auto v : adj[u]) {
                if (bel[u] != bel[v]) {
                    if (bel[u] < bel[v]) {
                        g.edges.emplace_back(bel[u], bel[v]);
                    }
                } else if (u < v) {
                    g.cnte[bel[u]]++;
                }
            }
        }
        return g;
    }
};
