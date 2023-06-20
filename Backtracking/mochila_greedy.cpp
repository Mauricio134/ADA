#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX = 4;
int s[MAX];
int soa[MAX];


int mochilaVoraz(int nivel, int n, int W, int wt[], int val[]) {
    if (n == 0|| W == 0)
        return 0;
    if (wt[n - 1] > W)
        return mochilaVoraz(nivel, n - 1, W, wt, val);
    else
        return max(val[n - 1] + mochilaVoraz(nivel, n - 1, W - wt[n - 1], wt, val),mochilaVoraz(nivel, n - 1, W, wt, val));
}

void GENERAR(int nivel,int p[], int b[], int &pact, int &bact) {
    s[nivel-1] = s[nivel-1] + 1;
    pact = pact + p[nivel-1]*s[nivel-1];
    bact = bact + b[nivel-1]*s[nivel-1];
    return;
}

bool SOLUCION(int nivel, int pact, int n, int M) {
    return (nivel == n) && (pact <= M);
}

bool CRITERIO(int nivel, int pact, int n, int M, int voa, int bact, int p[], int b[]) {
    if(pact>M || nivel == n) return false;
    float bestimado = bact + floor(mochilaVoraz(nivel+1,n,M-pact, p, b));
    return bestimado > voa;
}

bool MASHERMANOS(int nivel) {
    return s[nivel-1] < 1;
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
    int voa = -INF;
    int pact = 0, bact = 0;
    while (nivel > 0) {
        GENERAR(nivel, p, b, pact, bact);
        if ((SOLUCION(nivel,pact,n, M)) && (bact > voa)) {
            voa = bact;
            for (int i = 0; i < n; i++)
            {
                soa[i] = s[i];
            }
        }
        if (CRITERIO(nivel, pact, n, M, voa, bact, p, b)) {
            nivel = nivel + 1;
        }
        else {
            while ((!(MASHERMANOS(nivel))) && (nivel > 0) ) {
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