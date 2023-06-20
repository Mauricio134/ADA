#include <iostream>
#include <vector>

using namespace std;

// Función para intercambiar dos elementos en un arreglo
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef bool (*Funciones)(int, int);
bool mayor(int a, int b){
  return a >= b;
};

bool menor(int a, int b){
  return a <= b;
};

// Función que selecciona el último elemento como pivote y coloca los elementos menores a la izquierda del pivote y los mayores a la derecha del pivote
int partition(vector<int> &arr, int low, int high, Funciones* sec, int ite) {
    int pivot = arr[high]; // Seleccionamos el último elemento como pivote
    int i = (low - 1); // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (sec[ite](arr[j], pivot)) {
            i++; // Incrementamos el índice del elemento más pequeño
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función principal que implementa el algoritmo Quicksort
void quickSort(vector<int>& arr, int low, int high, Funciones* sec, int ite) {
    if (low < high) {
        // Obtenemos el índice de partición, arr[p] está en el lugar correcto
        int partitionIndex = partition(arr, low, high, sec, ite);

        // Llamada recursiva a Quicksort para los elementos antes y después de la partición
        quickSort(arr, low, partitionIndex - 1, sec, ite);
        quickSort(arr, partitionIndex + 1, high, sec, ite);
    }
}

// Función para imprimir el arreglo
void printArray(vector<int> arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Ejemplo de uso del algoritmo Quicksort
int main() {
    vector<int> arr = {9 ,1, 3, 5, 0, 4, 2, 6, 8, 7};
    Funciones* sec = new Funciones[2];
    sec[0] = &mayor;
    sec[1] = &menor;
    quickSort(arr, 0, arr.size() - 1, sec, 1);
    printArray(arr, arr.size());
    
    return 0;
}

