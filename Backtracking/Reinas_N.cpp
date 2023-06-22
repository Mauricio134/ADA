#include <iostream>
#include <cmath>

using namespace std;

bool comprobar(int reinas[], int n, int k) {
    for (int i = 0; i < k; i++) {
        if ((reinas[i] == reinas[k]) || (abs(k - i) == abs(reinas[k] - reinas[i]))) {
            return false;
        }
    }
    return true;
}

void print(int reinas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << reinas[i] << " ";
    }
    cout << endl;
}

void NReinas(int reinas[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) reinas[i] = -1;
    while (k >= 0) {
        reinas[k]++;
        while ((reinas[k] < n) && !comprobar(reinas, n, k)) reinas[k]++;
        if (k == n - 1) {
            print(reinas, n);
        }
        if (reinas[k] < n) {
            k++;
            reinas[k] = -1;
        } else {
            k--;
        }
    }
}

int main() {
    int reinas[4];
    int n = 4;
    NReinas(reinas, n);
    
    return 0;
}
