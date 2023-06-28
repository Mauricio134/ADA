#include <iostream>
#include <vector>

using namespace std;

bool backtrack(vector<vector<bool>>& laberinto, vector<vector<bool>>& visitado, int fila, int columna, int fila_salida, int columna_salida, vector<pair<int, int>>& camino) {
    if (fila == fila_salida && columna == columna_salida) {
        camino.push_back(make_pair(fila, columna));
        return true;
    }

    visitado[fila][columna] = true;

    int movimientos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int k = 0; k < 4; k++) {
        int nueva_fila = fila + movimientos[k][0];
        int nueva_columna = columna + movimientos[k][1];

        if (nueva_fila >= 0 && nueva_fila < laberinto.size() && nueva_columna >= 0 && nueva_columna < laberinto[0].size()
            && laberinto[nueva_fila][nueva_columna] && !visitado[nueva_fila][nueva_columna]) {
            if (backtrack(laberinto, visitado, nueva_fila, nueva_columna, fila_salida, columna_salida, camino)) {
                camino.push_back(make_pair(fila, columna));
                return true;
            }
        }
    }

    return false;
}

bool encontrarCamino(vector<vector<bool>>& laberinto, int fila_inicio, int columna_inicio, int fila_salida, int columna_salida, vector<pair<int, int>>& camino) {
    int n = laberinto.size();
    int m = laberinto[0].size();

    vector<vector<bool>> visitado(n, vector<bool>(m, false));

    return backtrack(laberinto, visitado, fila_inicio, columna_inicio, fila_salida, columna_salida, camino);
}

int main() {
    vector<vector<bool>> laberinto = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 1}
    };

    int fila_inicio = 0;
    int columna_inicio = 0;
    int fila_salida = 3;
    int columna_salida = 3;

    vector<pair<int, int>> camino;

    bool existeCamino = encontrarCamino(laberinto, fila_inicio, columna_inicio, fila_salida, columna_salida, camino);

    if (existeCamino) {
        cout << "Se encontró un camino desde la casilla de inicio hasta la casilla de salida:" << endl;
        for (int i = camino.size() - 1; i >= 0; i--) {
            cout << "(" << camino[i].first << ", " << camino[i].second << ")" << endl;
        }
    } else {
        cout << "No se encontró un camino válido desde la casilla de inicio hasta la casilla de salida." << endl;
    }

    return 0;
}
