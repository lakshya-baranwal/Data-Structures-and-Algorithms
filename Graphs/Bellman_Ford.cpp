 /*
 *    Bellman-Ford Algorithm (Template Class)
 *
 *    Description:
 *    -----------------
 *    The Bellman-Ford algorithm computes the shortest path
 *    from a single source to all other vertices in a weighted graph.
 *    It works with both directed and undirected graphs and supports negative edges.
 *    Unlike Dijkstra, it can detect negative weight cycles.
 *
 *    Complexity:
 *    -----------------
 *    Time Complexity: O(V * E)
 *    Space Complexity: O(V)
 *    Where V = vertices, E = edges.
 *
 *    Features:
 *    -----------------
 *    - Detects negative cycles
 *    - Works for both directed and undirected graphs (modify addEdge)
 */
const ll INF = 1e18;
template <typename T>
class BellmanFord {
    struct Edge {
        int u, v;
        T w;
    };

    int n;
    vector<Edge> edges;
    const T INF;

public:
    BellmanFord(int n, T INF_VAL) : n(n), INF(INF_VAL) {}

    // Add edge u -> v with weight w
    void addEdge(int u, int v, T w, bool undirected = false) {
        edges.push_back({u, v, w});
        if (undirected) edges.push_back({v, u, w});
    }

    // Run Bellman-Ford from source s
    vector<T> run(int s, bool &hasNegCycle) {
        vector<T> dist(n, INF);
        dist[s] = 0;
        hasNegCycle = false;

        for (int i = 0; i < n - 1; i++) {
            for (auto &e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        // Check for negative cycle
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                hasNegCycle = true;
                break;
            }
        }

        return dist;
    }
};
