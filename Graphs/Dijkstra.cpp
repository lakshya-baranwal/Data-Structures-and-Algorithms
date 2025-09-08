// Dijsktra in O((V + E) log V)

template <typename T>
vector<T> dijkstra(ll v, vector<vector<ll>> adj[], ll s)
{
    vector<bool> explored(v + 1, 0);
    vector<T> dist(v + 1, numeric_limits<T>::max());
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        ll node = pq.top().second;
        pq.pop();
        if (explored[node] == 1)
            continue;
        explored[node] = 1;
        for (ll j = 0; j < (ll)adj[node].size(); j++)
        {
            ll neighbour = adj[node][j][0];
            T weight = adj[node][j][1];
            if (!explored[neighbour] && (dist[node] + weight < dist[neighbour]))
            {
                dist[neighbour] = dist[node] + weight;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }
    return dist;
}
