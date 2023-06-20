#include <iostream>
#include <vector>
using namespace std;

// Función para mezclar dos subarreglos ordenados
void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mezclar los arreglos temporales de vuelta en arr[l..r]

    i = 0; // Índice inicial del primer subarreglo
    j = 0; // Índice inicial del segundo subarreglo
    k = l; // Índice inicial del subarreglo mezclado
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal que implementa el algoritmo Merge Sort
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        // Encuentra el punto medio para dividir el arreglo en dos mitades
        int m = l + (r - l) / 2;

        // Llamada recursiva para ordenar la primera mitad
        mergeSort(arr, l, m);
        // Llamada recursiva para ordenar la segunda mitad
        mergeSort(arr, m + 1, r);

        // Mezclar las dos mitades ordenadas
        merge(arr, l, m, r);
    }
}

void printArray(vector<int> arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    mergeSort(arr, 0, arr.size()-1);
    printArray(arr, arr.size());

    return 0;
}
