// Euler Tour Technique

// ------------------------
// Type 1: Flatten Tree (1 entry per node)
// ------------------------
void dfs_flatten(int node = 0, int parent = -1) {
    tin[node] = timer;
    euler[timer++] = node; // enter once
    for (int v : graph[node]) {
        if (v != parent) dfs_flatten(v, node);
    }
    tout[node] = timer; // subtree = [tin[node], tout[node])
}

// ------------------------
// Type 2: Full Euler Tour (enter + exit each node)
// ------------------------
void dfs_full(int node = 0, int parent = -1) {
    euler[timer++] = node; // enter
    for (int v : graph[node]) {
        if (v != parent) {
            dfs_full(v, node);
            euler[timer++] = node; // exit after child
        }
    }
}

/*
Applications:
- Type 1: subtree queries, Mo's algorithm, distinct colors in subtree
- Type 2: LCA queries, path queries, segment tree based algorithms
*/
