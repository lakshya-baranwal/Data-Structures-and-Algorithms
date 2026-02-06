/* author: jiangly */
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

struct HLD {
    int n;
    vector<int> siz, top, dep, parent, in, out, ord;
    vector<vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) { init(n); }

    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        ord.resize(n);
        cur = 0;
        adj.assign(n, {});
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Preprocess tree in O(n)
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }

    // First DFS: compute subtree sizes and reorder heavy child first in O(n)
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                swap(v, adj[u][0]); // ensure heavy child is first
            }
        }
    }

    // Second DFS: assign entry/exit times and chain tops in O(n)
    void dfs2(int u) {
        in[u] = cur++;
        ord[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = (v == adj[u][0] ? top[u] : v);
            dfs2(v);
        }
        out[u] = cur;
    }

    // Compute LCA(u, v) in O(log n)
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) u = parent[top[u]];
            else v = parent[top[v]];
        }
        return dep[u] < dep[v] ? u : v;
    }

    // Compute distance between u and v in O(log n)
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    // Jump k steps up from u in O(log n)
    int jump(int u, int k) {
        if (dep[u] < k) return -1;
        int d = dep[u] - k;
        while (dep[top[u]] > d) u = parent[top[u]];
        return ord[in[u] - dep[u] + d];
    }

    // Check if u is ancestor of v in O(1)
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }

    // Get parent of u in tree rooted at v in O(log n)
    int rootedParent(int u, int v) {
        swap(u, v);
        if (u == v) return u;
        if (!isAncester(u, v)) return parent[u];
        auto it = upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }

    // Get size of subtree of v when tree is rooted at u in O(1)
    int rootedSize(int u, int v) {
        if (u == v) return n;
        if (!isAncester(v, u)) return siz[v];
        return n - siz[rootedParent(u, v)];
    }

    // Compute LCA of (a, b, c) when rooted in O(log n)
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

void solve() {
    int n; cin >> n;

    HLD t(n);

    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        t.addEdge(u, v);
    }

    t.work();

    // Code
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}
