#include <iostream>
#include <cstring>

using namespace std;

void print(int X[], int k){
    for(int i = 0; i < k; i++){
        cout << X[i] << " ";
    }
    cout << endl;
}

void SumaSubconjuntos(int X[], int W[], int M, int k, int s, int r) {
    X[k] = 1;
    if (s + W[k] == M) {
        print(X, k + 1);
    } else {
        if (s + W[k] + W[k + 1] <= M) {
            SumaSubconjuntos(X, W, M, k + 1, s + W[k], r - W[k]);
        }
        if (s + r - W[k] >= M && s + W[k + 1] <= M) {
            X[k] = 0;
            SumaSubconjuntos(X, W, M, k + 1, s, r - W[k]);
        }
    }
}


int main(){
    int W[6] = {5, 10, 12, 13, 15, 18};
    int M = 30;
    int X[6];
    memset(X,0,sizeof(X));
    SumaSubconjuntos(X,W,M,1,0,73);
    
    return 0;
}
