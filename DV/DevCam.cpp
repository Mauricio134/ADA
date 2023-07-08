#include <iostream>
#include <cstring>

using namespace std;

void DevolverCambio(int n,int P, int C[], int X[]){
    int act = 0;
    int j = n-1;
    while(act != P){
        while(C[j] <= (P-act) && j >= 0){
            act -= C[j]*X[j];
            X[j] = X[j]+1;
            act += C[j]*X[j];
        }
        j--;
        if(j < 0 && act != P) {
            cout << "No existe solución";
            cout << j << endl;
            return;
        }
    }
    for(int i = 0; i < n; i++){
        cout << X[i] << endl;
    }
}

int main()
{
    int C[] = {1,90,100};
    int P = 180;
    const int n = sizeof(C)/sizeof(C[0]);
    int X[n];
    memset(X,0,sizeof(X));
    DevolverCambio(n,P,C,X);
    return 0;
}
