
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

int main() {
    int n, m;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v
            >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int totalCost = 0, count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < m && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int p1 = findParent(parent, u);
        int p2 = findParent(parent, v);

        if (p1 != p2) {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            parent[p1] = p2;
            totalCost += edges[i].weight;
            count++;
        }
    }

    if (count != n - 1) {
        cout << "Graph is disconnected.\n";
    } else {
        cout << "Total minimum cost: "
             << totalCost << endl;
    }

    return 0;
}
