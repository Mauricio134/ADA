#include <iostream>

using namespace std;

const int N = 3;
int pase[N] = {true, true, true};

int MOCHILA(int W, int w[], int b[], int n, int v[]) {
    int pesoact = 0;
    while(pesoact < W){
        int mejor = -1;
        int k = 0;
        for(int i = 0; i < n-1; i++){
            if(b[i] > mejor && pase[i]){
                mejor = b[i];
                k = i;
            }
        }
        if (mejor == -1) {
            break;
        }

        if (pesoact + w[k] <= W) {
            double uno = 1.0;
            v[k] = uno;
            double p2 = w[mejor];
            pesoact = pesoact + w[mejor];
        } else {
            v[k] = 0;
            pesoact = W;
        }
    }
}

int main() {
    int W = 50;
    int n = 3;
    int b[] = { 120, 100, 60 };
    int w[] = { 30, 20, 10 };
    int VALORES[3] = { 0, 0, 0 };
    int mejor = MOCHILA(W, w, b, n, VALORES);
    cout << mejor << endl;
    for (int i = 0; i < n; i++) {
        cout << VALORES[i] << " ";
    }
    return 0;
}
