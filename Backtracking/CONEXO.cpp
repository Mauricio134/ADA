#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool esConexo(vector<vector<int>>& grafo) {
    int numVertices = grafo.size();

    if (numVertices == 0) {
        return true;
    }

    vector<bool> visitados(numVertices, false);
    queue<int> cola;

    int verticeInicial = 0;
    cola.push(verticeInicial);
    visitados[verticeInicial] = true;

    while (!cola.empty()) {
        int verticeActual = cola.front();
        cola.pop();

        for (int adyacente : grafo[verticeActual]) {
            if (!visitados[adyacente]) {
                cola.push(adyacente);
                visitados[adyacente] = true;
            }
        }
    }

    for (bool visitado : visitados) {
        if (!visitado) {
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
        {1, 2},
        {}
    };

    // Ejemplo de grafo conexo
    vector<vector<int>> grafo2 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if (esConexo(grafo1)) {
        cout << "El grafo 1 es conexo." << endl;
    } else {
        cout << "El grafo 1 no es conexo." << endl;
    }

    if (esConexo(grafo2)) {
        cout << "El grafo 2 es conexo." << endl;
    } else {
        cout << "El grafo 2 no es conexo." << endl;
    }

    return 0;
}
