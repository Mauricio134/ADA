#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool esBipartido(vector<vector<int>>& grafo, int inicio) {
    int n = grafo.size();
    vector<int> colores(n, 0);
    colores[inicio] = 1;
    queue<int> cola;
    cola.push(inicio);

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        for (int adyacente : grafo[actual]) {
            if (colores[adyacente] == 0) {
                colores[adyacente] = -colores[actual];
                cola.push(adyacente);
            }
            else if (colores[adyacente] == colores[actual]) {
                return false;
            }
        }
    }
}

bool esBipartido(vector<vector<int>>& grafo) {
    int n = grafo.size();
    for (int i = 0; i < n; i++) {
        if (!esBipartido(grafo, i)) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> grafo1 = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2}
    };
    vector<vector<int>> grafo2 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if (esBipartido(grafo1)) {
        cout << "El grafo 1 es bipartido." << endl;
    } else {
        cout << "El grafo 1 no es bipartido." << endl;
    }

    if (esBipartido(grafo2)) {
        cout << "El grafo 2 es bipartido." << endl;
    } else {
        cout << "El grafo 2 no es bipartido." << endl;
    }

    return 0;
}
