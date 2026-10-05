#include <iostream>
using namespace std;

#define INF 9999

int n;
int cost[10][10];
int visited[10];
int minCost = INF;

void tsp(int current, int count, int totalCost) {
    // All cities visited
    if (count == n) {
        if (cost[current][0] != 0) {
            int finalCost = totalCost + cost[current][0];

            if (finalCost < minCost)
                minCost = finalCost;
        }
        return;
    }

    // Visit unvisited cities
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[current][i] != 0) {
            visited[i] = 1;

            tsp(i, count + 1, totalCost + cost[current][i]);

            visited[i] = 0;
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // Start from city 0
    visited[0] = 1;

    tsp(0, 1, 0);

    cout << "\nMinimum cost = " << minCost << endl;

    return 0;
}
