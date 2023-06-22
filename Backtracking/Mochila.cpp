#include <iostream>
#include <cstring>
#include <numeric>

using namespace std;

const int INF = 1e9;
const int MAX = 4;
int s[MAX];
int soa[MAX];

void GENERAR(int nivel,int p[], int b[], int &pact, int &bact) {
    s[nivel-1] = s[nivel-1] + 1;
    pact = pact + p[nivel-1]*s[nivel-1];
    bact = bact + b[nivel-1]*s[nivel-1];
    return;
}

bool SOLUCION(int nivel, int pact, int n, int M) {
    return (nivel == n) && (pact <= M);
}

bool CRITERIO(int nivel, int pact, int n, int M) {
    return (nivel < n) && (pact <= M);
}

bool MASHERMANOS(int nivel) {
    return s[nivel-1] < 1; //return s[nivel-1] > 0; Beneficio Minimo y return s[nivel-1] < 1; Beneficio Maximo 
}
void RETROCEDER(int& nivel, int p[], int b[], int& pact, int& bact) {
    pact = pact - p[nivel-1] * s[nivel-1];
    bact = bact - b[nivel-1] * s[nivel-1];
    s[nivel-1] = -1;
    nivel = nivel - 1;
    return;
}

void Mochila(int p[], int b[], int M, int n) {
    int nivel = 1;
    //int voa = accumulate(b, b + n, 0) + 1;// Beneficio Minimo
    int voa = -INF; //Beneficio Maximo
    int pact = 0, bact = 0;
    while (nivel > 0) {
        GENERAR(nivel, p, b, pact, bact);
        if ((SOLUCION(nivel,pact,n, M)) && (bact > voa)) { // (bact < voa) Beneficio Minimo y (bact > voa) Beneficio Maximo
            voa = bact;
            for (int i = 0; i < n; i++)
            {
                soa[i] = s[i];
            }
        }
        if (CRITERIO(nivel, pact, n, M)) {
            nivel = nivel + 1;
        }
        else {
            while (!(MASHERMANOS(nivel)) && (nivel > 0)) {
                RETROCEDER(nivel, p, b, pact, bact);
            }
        }
    }
}

int main()
{
    int n = 4;
    int M = 7;
    int b[] = { 2,3,4,5 };
    int p[] = { 1,2,3,4 };
    memset(s, -1, sizeof(s));
    memset(soa, 0, sizeof(soa));
    Mochila(p, b, M, n);
    for (int i = 0; i < n; i++)
    {
        cout << soa[i] << endl;
    }
}