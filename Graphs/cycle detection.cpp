//Cycle detection in a directed graph

//Using BFS traversal

bool isCycleBFS(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;

        for(auto v : adj[u]){
            if(!visited[v] && isCycleBFS(adj, v, visited, inRecursion)){
                return true;
            }
            if(visited[v] && inRecursion[v]) return true;
        }
        inRecursion[u] = false;
    return false;
}

//In the main function, initialisation can be done depending upon the type of question and how we are going to use this concept.

        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                isCycleBFS(graph, i, visited, inRecursion);
            }
        } 


//Using DFS (Also known as TOPOLOGICAL SORTING)

//use the concept of indegree and maintain a queue to access nodes in a particular way.
