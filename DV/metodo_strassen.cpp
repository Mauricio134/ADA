#include <iostream>
#include <vector>

using namespace std;

// Función para sumar dos matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// Función para restar dos matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

// Función para multiplicar dos matrices utilizando el algoritmo de Strassen
vector<vector<int>> multiplicacionStrassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Caso base: Matrices 1x1
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Particionando las matrices en submatrices
    int mitad = n / 2;

    vector<vector<int>> A11(mitad, vector<int>(mitad));
    vector<vector<int>> A12(mitad, vector<int>(mitad));
    vector<vector<int>> A21(mitad, vector<int>(mitad));
    vector<vector<int>> A22(mitad, vector<int>(mitad));

    vector<vector<int>> B11(mitad, vector<int>(mitad));
    vector<vector<int>> B12(mitad, vector<int>(mitad));
    vector<vector<int>> B21(mitad, vector<int>(mitad));
    vector<vector<int>> B22(mitad, vector<int>(mitad));

    for (int i = 0; i < mitad; i++) {
        for (int j = 0; j < mitad; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mitad];
            A21[i][j] = A[i + mitad][j];
            A22[i][j] = A[i + mitad][j + mitad];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mitad];
            B21[i][j] = B[i + mitad][j];
            B22[i][j] = B[i + mitad][j + mitad];
        }
    }

    // Calculando los productos de Strassen recursivamente
    vector<vector<int>> P1 = multiplicacionStrassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    vector<vector<int>> P2 = multiplicacionStrassen(sumarMatrices(A21, A22), B11);
    vector<vector<int>> P3 = multiplicacionStrassen(A11, restarMatrices(B12, B22));
    vector<vector<int>> P4 = multiplicacionStrassen(A22, restarMatrices(B21, B11));
    vector<vector<int>> P5 = multiplicacionStrassen(sumarMatrices(A11, A12), B22);
    vector<vector<int>> P6 = multiplicacionStrassen(restarMatrices(A21, A11), sumarMatrices(B11, B12));
    vector<vector<int>> P7 = multiplicacionStrassen(restarMatrices(A12, A22), sumarMatrices(B21, B22));

    // Calculando las submatrices del resultado
    vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(P1, P4), P5), P7);
    vector<vector<int>> C12 = sumarMatrices(P3, P5);
    vector<vector<int>> C21 = sumarMatrices(P2, P4);
    vector<vector<int>> C22 = sumarMatrices(restarMatrices(sumarMatrices(P1, P3), P2), P6);

    // Construyendo la matriz resultante
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < mitad; i++) {
        for (int j = 0; j < mitad; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mitad] = C12[i][j];
            C[i + mitad][j] = C21[i][j];
            C[i + mitad][j + mitad] = C22[i][j];
        }
    }

    return C;
}

// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Ejemplo de uso
    vector<vector<int>> A = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};

    vector<vector<int>> B = {{16, 15, 14, 13},
                             {12, 11, 10, 9},
                             {8, 7, 6, 5},
                             {4, 3, 2, 1}};

    cout << "Matriz A:" << endl;
    imprimirMatriz(A);

    cout << "Matriz B:" << endl;
    imprimirMatriz(B);

    vector<vector<int>> resultado = multiplicacionStrassen(A, B);

    cout << "Resultado de la multiplicación:" << endl;
    imprimirMatriz(resultado);

    return 0;
}
