#include <bits/stdc++.h>
using namespace std;

void primsAlgorithm(int V, vector<vector<pair<int, int>>> &adj) {
    // {weight, vertex}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    vector<bool> visited(V, false);

    // Start from vertex 0
    pq.push({0, 0});

    int totalWeight = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        totalWeight += weight;

        if (weight != 0) {
            cout << u << " - " << weight << "\n";
        }

        // Visit all adjacent vertices
        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << "Total weight = " << totalWeight << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    // Input: u v weight
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    primsAlgorithm(V, adj);

    return 0;
}
