#include <iostream>
#include <vector>

using namespace std;

bool tieneCiclosUtil(vector<vector<int>>& grafo, vector<bool>& visitados, vector<bool>& enPila, int nodo) {
    visitados[nodo] = true;
    enPila[nodo] = true;

    for (int adyacente : grafo[nodo]) {
        if (!visitados[adyacente]) {
            if (tieneCiclosUtil(grafo, visitados, enPila, adyacente))
                return true;
        } else if (enPila[adyacente]) {
            return true;
        }
    }

    enPila[nodo] = false;
    return false;
}

bool tieneCiclos(vector<vector<int>>& grafo) {
    int numVertices = grafo.size();
    vector<bool> visitados(numVertices, false);
    vector<bool> enPila(numVertices, false);

    for (int nodo = 0; nodo < numVertices; nodo++) {
        if (!visitados[nodo]) {
            if (tieneCiclosUtil(grafo, visitados, enPila, nodo))
                return true;
        }
    }

    return false;
}

int main() {
    // Ejemplo de grafo dirigido con ciclos
    vector<vector<int>> grafo1 = {
        {1},
        {2},
        {0},
        {3},
        {4},
        {5, 7},
        {6},
        {4}
    };

    // Ejemplo de grafo dirigido acíclico (DAG)
    vector<vector<int>> grafo2 = {
        {1},
        {2},
        {3},
        {4},
        {5},
        {},
        {}
    };

    if (tieneCiclos(grafo1)) {
        cout << "El grafo 1 tiene ciclos." << endl;
    } else {
        cout << "El grafo 1 es un grafo dirigido acíclico (DAG)." << endl;
    }

    if (tieneCiclos(grafo2)) {
        cout << "El grafo 2 tiene ciclos." << endl;
    } else {
        cout << "El grafo 2 es un grafo dirigido acíclico (DAG)." << endl;
    }

    return 0;
}
