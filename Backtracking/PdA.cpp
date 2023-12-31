#include <iostream>
#include <cstring>

using namespace std;


const int MAX = 3;
const int INF = 1e9;
int s[MAX];
int soa[MAX];
int usada[MAX]; 

void generar(int &nivel, int (&B)[3][3], int &bact){
    s[nivel-1] = s[nivel-1]+1;
    if(s[nivel-1] == 1){
        bact = bact + B[nivel-1][s[nivel-1]-1];
    }
    else{
        bact = bact + B[nivel-1][s[nivel-1]-1] -B[nivel-1][s[nivel-1]-2];
    }
}

bool criterio(int &nivel){
    for(int i = 0; i < nivel-1; i++){
        if(s[nivel-1] == s[i]){
            return false;
        }
    }
    return true;
}

bool solucion(int &nivel, int n){
    return nivel == n && criterio(nivel);
}

bool mashermanos(int &nivel, int n){
    return s[nivel-1] < n;
}

void retroceder(int &nivel, int &bact, int (&B)[3][3]){
    bact = bact - B[nivel-1][s[nivel-1]-1];
    s[nivel-1] = 0;
    nivel = nivel - 1;
}

void backtracking(int (&B)[3][3]){
    int n = sizeof(B)/sizeof(B[0]);
    int nivel = 1;
    int voa = -INF;
    int bact = 0;
    while(nivel != 0){
        generar(nivel, B, bact);
        if(solucion(nivel, n) && (bact > voa)){
            voa = bact;
            for(int i = 0; i < n; i++){
                soa[i] = s[i];
            }
        }
        if(criterio(nivel)){
            nivel = nivel + 1;
        }
        else{
            while(!mashermanos(nivel, n) && (nivel>0)){
                retroceder(nivel, bact, B);
            }
        }
    }
}


int main() {
    int B[3][3]={
        {4,9,1},
        {7,2,3},
        {6,3,5}
    };
    memset(s,-1,sizeof(s));
    memset(soa,0,sizeof(soa));
    memset(usada,0,sizeof(usada));
    backtracking(B);
    for(int i = 0; i < 3; i++){
        cout << soa[i] << " ";
    }
    int best = 0;
    for(int i = 0; i < 3; i++){
        best += B[i][soa[i]-1];
    }
    cout << best << endl;
    return 0;
}