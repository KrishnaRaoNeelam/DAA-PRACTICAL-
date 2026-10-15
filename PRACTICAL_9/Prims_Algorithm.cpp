
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<bool> visited(n, false);
    visited[0] = true;

    int edges = 0, totalCost = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int minCost = 1000000;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] != 0 &&
                        cost[i][j] < minCost) {
                        minCost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            cout << "Graph is disconnected.\n";
            return 0;
        }

        cout << u << " - " << v
             << " : " << minCost << endl;

        visited[v] = true;
        totalCost += minCost;
        edges++;
    }

    cout << "Total minimum cost: " << totalCost << endl;

    return 0;
}
