/*
 * Flows and Cuts
 *
 * Basics:
 * - Defined on weighted directed graphs (capacities on edges).
 * - Any feasible flow <= any cut (weak duality).
 * - Maximum Flow = Minimum Cut (max-flow min-cut theorem).
 *
 * Classical Algorithms and their complexities:
 
 * - Ford–Fulkerson:
 *   O(E*max_flow), may not terminate with irrational capacities.
 
 * - Edmonds–Karp:
 *   O(V*E*E).
 * - Scaling Algorithm:
 *   O(E*E*log U), where U is maximum capacity.
 
 * - Dinic’s Algorithm:
 *   O(V*V*E) in general graphs,
 *   O(min(V^(2/3), E^(1/2))*E) for unit capacities.
 
 * - MPM Algorithm:
 *   O(V*V*V).
 
 * - Push-Relabel:
 *   O(V*V**E) in general,
 *   O(V*V*V) with heuristics like gap relabeling.
 *
 * Applications:
 * - Edge-Disjoint Paths:
 *   Maximum number of edge-disjoint paths = max flow (with unit capacities).
 * - Node-Disjoint Paths:
 *   Split each node into in/out pair with unit edge between them.
 * - Maximum Matching:
 *   Bipartite matching reducible to max-flow.
 * - Node-Disjoint Path Cover:
 *   Cover DAG with minimum number of node-disjoint paths.
 * - General Path Cover:
 *   Extension of path cover problems in DAGs.
 *
 * Notes:
 * - Flow extends to circulations with demands, min-cost flow, and multi-commodity flows.
 * - Min-cut applications: image segmentation, network reliability, clustering.
 */
