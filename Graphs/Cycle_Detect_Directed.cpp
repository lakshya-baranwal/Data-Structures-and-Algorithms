// Cycle Detection in Directed Graph using BFS (Kahn's Algorithm)

    vector<vector<int>> adj(n);
    vector<int> ind(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v; // directed graph u --> v edge
        --u, --v;
        adj[u].push_back(v);
        ind[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) if(ind[i] == 0) q.push(i);
    
    int cnt = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        cnt++;
        for(auto v: adj[u]){
            if(--ind[v] == 0) q.push(v);
        }
    }

    if(cnt == n) cout << "NO\n";  // no cycle
    else cout << "YES\n";         // cycle exists
}
