#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> num;
vector<int> low;
vector<bool> visited;
vector<bool> isArticulationPoint;
int counter;

void dfs(int v, int parent) {
    visited[v] = true;
    num[v] = low[v] = counter++;

    int children = 0;
    bool isArticulation = false;

    for (int u : graph[v]) {
        if (u == parent)
            continue;

        if (!visited[u]) {
            children++;
            dfs(u, v);
            low[v] = min(low[v], low[u]);

            if (low[u] >= num[v])
                isArticulation = true;
        } else {
            low[v] = min(low[v], num[u]);
        }
    }

    if ((parent == -1 && children > 1) || (parent != -1 && isArticulation))
        isArticulationPoint[v] = true;
}

void findArticulationPoints(int n) {
    num.resize(n, -1);
    low.resize(n, -1);
    visited.resize(n, false);
    isArticulationPoint.resize(n, false);
    counter = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Crear el grafo
    graph.resize(n);

    // Leer las aristas
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Encontrar los puntos de articulación
    findArticulationPoints(n);

    // Imprimir los puntos de articulación
    cout << "Puntos de articulación: ";
    for (int i = 0; i < n; i++) {
        if (isArticulationPoint[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
