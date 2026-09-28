#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Disjoint Set Union (Union-Find)
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression

        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false; // Would create a cycle

        // Union by rank
        if (rank[a] < rank[b])
            swap(a, b);

        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;

        return true;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by increasing weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    DSU dsu(V);

    int mstWeight = 0;
    vector<Edge> mst;

    // Pick edges that don't form a cycle
    for (Edge edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            mstWeight += edge.weight;

            if (mst.size() == V - 1)
                break;
        }
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (Edge edge : mst) {
        cout << edge.u << " - " << edge.v
             << " : " << edge.weight << endl;
    }

    cout << "Total weight of MST = " << mstWeight << endl;

    return 0;
}
