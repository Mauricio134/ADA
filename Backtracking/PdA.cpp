#include <iostream>
#include <cstring>

using namespace std;

const int N = 3;
const int INF = 1e9;
int s[N];
int soa[N];

void GENERAR(int nivel, int &bact, int (&B)[N][N]){
    s[nivel-1] = s[nivel-1] + 1;
    if(s[nivel-1] == 1){
        bact = bact + B[nivel-1][s[nivel-1]-1];
    }else{
        bact = bact + B[nivel-1][s[nivel-1]-1] - B[nivel-1][s[nivel-1]-2];
    }
}

bool CRITERIO(int nivel){
    for(int i = 0; i < nivel-1; i++){
        if(s[nivel-1] == s[i]){
            return false;
        }
    }
    return true;
}

bool SOLUCION(int nivel, int n){
    return (nivel==n) && CRITERIO(nivel);
}

bool MASHERMANOS(int nivel, int n){
    return s[nivel-1] < n;
}

void RETROCEDER(int &nivel, int &bact, int (&B)[N][N]){
    bact = bact - B[nivel-1][s[nivel-1]-1];
    s[nivel-1] = 0;
    nivel = nivel - 1;
}

void PDA(int n, int (&B)[N][N]){
    int nivel = 1;
    int voa = -INF;
    int bact = 0;
    do{
        GENERAR(nivel, bact, B);
        if (SOLUCION(nivel, n) && (bact > voa)){
            voa = bact;
            for(int i = 0; i < N; i++){
                soa[i] = s[i] + 1;
            }
        }

        else if (CRITERIO(nivel)){
            nivel = nivel + 1;
        }
        else{
            while(!MASHERMANOS(nivel, n) && nivel > 0){
                RETROCEDER(nivel, bact, B);
            }
        }
    }while(nivel > 0);
}

int main(){
    int B[3][3] = {
        {1,1,3},
        {1,3,1},
        {3,1,2}
    };
    int n = 3;
    memset(s,-1,sizeof(s));
    memset(soa, -1, sizeof(soa));
    PDA(n, B);
    for(int i = 0; i < n; i++){
        cout << soa[i] << " ";
    }
    return 0;
}
