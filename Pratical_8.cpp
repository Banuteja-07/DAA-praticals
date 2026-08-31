#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node])
    {
        if (!visited[next])
            DFS(next, graph, visited);
    }
}

void BFS(int start, vector<vector<int>>& graph)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(vertices);

    cout << "Enter edges:\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    DFS(start, graph, visited);

    cout << "\nBFS Traversal: ";
    BFS(start, graph);

    cout << endl;

    return 0;
}
