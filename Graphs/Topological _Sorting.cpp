/*
 * Topological Sorting in a Directed Acyclic Graph (DAG)
 *
 * Notes:
 *  Only applicable to DAGs (Directed Acyclic Graphs).
 *  Multiple valid topological orderings may exist.
 *  Two standard approaches:
 *     1. BFS-based (Kahn's Algorithm).
 *     2. DFS-based (postorder + reverse).
 * Time Complexity: O(V + E) for both methods.
 */

vector<int> topo;

// 1. BFS (Kahn’s Algorithm)
queue<int> q;
for (int i = 0; i < n; i++) if (ind[i] == 0) q.push(i);
while (!q.empty()) {
     int u = q.front(); q.pop();
     topo.push_back(u);
     for (int v : adj[u]) if (--ind[v] == 0) q.push(v);
}

// 2. DFS (postorder + reverse)
vector<bool> vis(n, false);
function<void(int)> dfs = [&](int u) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfs(v);
    topo.push_back(u);
};
for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
reverse(topo.begin(), topo.end());

