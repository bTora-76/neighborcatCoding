#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int V, E;
    cin >> V >> E;

    // Use adjacency list instead of matrix for efficiency
    vector<vector<pii>> adj(V+1); // Stores {neighbor, weight}

    // Read input edges
    for (int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    int start;
    cin >> start;

    // Min heap (priority queue) for selecting minimum edge
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Visited array
    vector<bool> visited(V, false);

    int res = 0; // Store sum of MST edge weights

    // Start with vertex 0
    pq.push({0, start});

    while (!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if (visited[u]) continue; // Skip visited vertices

        res += wt;
        visited[u] = true;
        // cout << wt << endl;

        // Push adjacent edges to priority queue
        for (auto [v, weight] : adj[u]) {
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    cout << res;

    return 0;
}
