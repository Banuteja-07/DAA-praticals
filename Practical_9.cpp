#include <iostream>
using namespace std;

const int MAX_VERTICES = 10;
const int INF = 9999;

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > MAX_VERTICES) {
        cout << "Invalid number of vertices. Please enter a value between 1 and 10.\n";
        return 1;
    }

    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; ++i) {
        for (int j = 0; j < MAX_VERTICES; ++j) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = INF;
            if (i == j) {
                graph[i][j] = 0;
            }
        }
    }

    cout << "Enter adjacency matrix (0 means no connection):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];

            if (i == j) {
                graph[i][j] = 0;
            } else if (graph[i][j] < 0) {
                cout << "Invalid edge weight. Please enter non-negative values.\n";
                return 1;
            } else if (graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    if (n == 1) {
        cout << "\nNo edges needed for a single vertex.\n";
        cout << "Minimum cost = 0\n";
        return 0;
    }

    bool selected[MAX_VERTICES] = {false};
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];

    for (int i = 0; i < n; ++i) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;
    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int count = 0; count < n - 1; ++count) {
        int minKey = INF;
        int u = -1;

        for (int i = 0; i < n; ++i) {
            if (!selected[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1) {
            cout << "Graph is disconnected. MST cannot be formed.\n";
            return 1;
        }

        selected[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!selected[v] && graph[u][v] != INF && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << " : " << graph[parent[i]][i] << endl;
        totalCost += graph[parent[i]][i];
    }

    cout << "Minimum cost = " << totalCost << endl;
    return 0;
}
