 /*
 *    Floyd-Warshall Algorithm (Template Class)
 *
 *    Description:
 *    -----------------
 *    The Floyd–Warshall algorithm is a classic dynamic programming approach
 *    to compute the shortest paths between all pairs of vertices in a weighted graph.
 *    It works with both directed and undirected graphs, and can handle negative edges
 *    (but not negative cycles).
 *
 *    Complexity:
 *    -----------------
 *    Time Complexity: O(V^3)
 *    Space Complexity: O(V^2)
 *    Where V is the number of vertices.
 *
 *    Features:
 *    -----------------
 *    - Supports template types (int, long long, double, etc.)
 *    - Detects negative cycles
 *    - Works for both directed and undirected graphs (modify addEdge) 
 */

const ll INF = 1e18;
template <typename T>
class FloydWarshall {
    int n;
    vector<vector<T>> dist;
    const T INF;

public:
    FloydWarshall(int n, T INF_VAL) : n(n), INF(INF_VAL) {
        dist.assign(n, vector<T>(n, INF));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
    }

    // Add edge u -> v with weight w
    // Modify this for directed graphs (remove the second assignment)
    void addEdge(int u, int v, T w) {
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w); // For undirected graph
    }

    // Run Floyd-Warshall Algorithm
    void run() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < n; j++) {
                    if (dist[k][j] == INF) continue;
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Get distance from u to v
    T getDistance(int u, int v) {
        return dist[u][v];
    }

    // Check if graph contains a negative cycle
    bool hasNegativeCycle() {
        for (int i = 0; i < n; i++) {
            if (dist[i][i] < 0) return true;
        }
        return false;
    }

    // Print distance matrix
    void printAllPairs() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }
};
