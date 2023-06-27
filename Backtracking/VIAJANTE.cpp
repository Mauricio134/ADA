#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 5;  // Número de ciudades

// Matriz de distancias entre las ciudades
int distances[N][N] = {
    {0, 3, 10, 11, 7},
    {3, 0, 8, 12, 9},
    {10, 8, 0, 9, 6},
    {11, 12, 9, 0, 5},
    {7, 9, 6, 5, 0}
};

// Variables globales para almacenar la mejor solución encontrada
vector<int> bestPath;
int bestDistance = INT_MAX;

// Función para calcular la distancia total de un recorrido
int calculateDistance(const vector<int>& path) {
    int distance = 0;
    for (int i = 0; i < N - 1; i++) {
        distance += distances[path[i]][path[i + 1]];
    }
    distance += distances[path[N - 1]][path[0]];  // Regreso al punto de partida
    return distance;
}

// Función recursiva para encontrar la solución óptima utilizando la técnica B&B
void branchAndBoundTSP(vector<int>& path, vector<bool>& visited, int currentDistance) {
    // Si hemos visitado todas las ciudades, comprobamos si esta solución es mejor que la mejor encontrada hasta ahora
    if (path.size() == N) {
        int totalDistance = currentDistance + distances[path[N - 1]][path[0]];  // Sumamos la distancia de regreso al punto de partida
        if (totalDistance < bestDistance) {
            bestDistance = totalDistance;
            bestPath = path;
        }
        return;
    }

    // Podamos la rama si la distancia actual es mayor o igual a la mejor distancia encontrada hasta ahora
    if (currentDistance >= bestDistance) {
        return;
    }

    // Generamos las ramas no visitadas y las exploramos recursivamente
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);

            int newDistance = currentDistance + distances[path[path.size() - 2]][i];
            branchAndBoundTSP(path, visited, newDistance);

            visited[i] = false;
            path.pop_back();
        }
    }
}

int main() {
    vector<int> path;  // Almacenará el recorrido óptimo
    vector<bool> visited(N, false);  // Almacenará el estado de visita de las ciudades

    path.push_back(0);  // Agregamos la primera ciudad al recorrido
    visited[0] = true;  // Marcamos la primera ciudad como visitada

    branchAndBoundTSP(path, visited, 0);

    cout << "Recorrido óptimo: ";
    for (int i = 0; i < N; i++) {
        cout << char('A' + bestPath[i]) << " ";
    }
    cout << "A" << endl;

    cout << "Distancia óptima: " << bestDistance << endl;

    return 0;
}
