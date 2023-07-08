#include <iostream>
#include <cstring>

using namespace std;


const int MAX = 100;
const int INF = 1e9;
int s[MAX];
int soa[MAX];

void generar(int &nivel, int h[], int l[], int &bact){
    s[nivel-1] = s[nivel-1]+1;
    bact += abs(h[nivel-1]-l[s[nivel-1]-1]);
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

void retroceder(int &nivel, int &bact, int h[], int l[]){
    bact = bact - abs(h[nivel-1]-l[s[nivel-1]-1]);
    s[nivel-1] = 0;
    nivel = nivel - 1;
}

void backtracking(int h[], int l[], int n){
    int nivel = 1;
    int voa = INF;
    int bact = 0;
    while(nivel != 0){
        generar(nivel, h, l, bact);
        if(solucion(nivel, n) && (bact < voa)){
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
                retroceder(nivel, bact, h, l);
            }
        }
    }
}


int main() {
    int h[] = {178,168,190,170};
    int l[] = {183,188,168,175};
    int n = sizeof(h)/sizeof(h[0]);
    memset(s,0,sizeof(s));
    memset(soa,0,sizeof(soa));
    backtracking(h,l,n);
    for(int i = 0; i < n; i++){
        cout << soa[i] << " ";
    }
    return 0;
}