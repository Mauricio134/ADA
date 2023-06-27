//problema 1:
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

void backtrack(vector<pair<int, bool> >& esquis, const vector<int>& alumnos, vector<int>& asignacion_actual, pair<int, vector<int> >& mejor_asignacion, int suma_diferencias, int indice) {
    // Caso base: si hemos asignado todos los esquís, comprobamos si esta asignación es mejor que la anterior
    if (indice == alumnos.size()) {
        if (suma_diferencias < mejor_asignacion.first) {
            mejor_asignacion.first = suma_diferencias;
            mejor_asignacion.second = asignacion_actual;
        }
        return;
    }

    // Backtracking
    for (int i = 0; i < esquis.size(); ++i) {
        if (!esquis[i].second) {  // Si el esquí no ha sido asignado aún
            esquis[i].second = true;
            asignacion_actual[indice] = i;

            // Actualizamos la suma de diferencias
            suma_diferencias += abs(alumnos[indice] - esquis[i].first);

            // Podamos la rama si la suma actual ya es mayor que la mejor encontrada
            if (suma_diferencias < mejor_asignacion.first) {
                backtrack(esquis, alumnos, asignacion_actual, mejor_asignacion, suma_diferencias, indice + 1);
            }

            // Retrocedemos
            suma_diferencias -= abs(alumnos[indice] - esquis[i].first);
            esquis[i].second = false;
            asignacion_actual[indice] = -1;
        }
    }
}

vector<int> asignar_esquis(const vector<int>& alturas, const vector<int>& longitudes) {
    vector<pair<int, bool> > esquis(longitudes.size(), make_pair(0, false));
    for (int i = 0; i < longitudes.size(); ++i) {
        esquis[i].first = longitudes[i];
    }

    vector<int> asignacion_actual(alturas.size(), -1);
    pair<int, vector<int> > mejor_asignacion = make_pair(INT_MAX, vector<int>());

    backtrack(esquis, alturas, asignacion_actual, mejor_asignacion, 0, 0);

    return mejor_asignacion.second;
}

int main() {
    vector<int> alturas;
    alturas.push_back(178);
    alturas.push_back(168);
    alturas.push_back(190);
    alturas.push_back(170);

    vector<int> longitudes;
    longitudes.push_back(183);
    longitudes.push_back(188);
    longitudes.push_back(168);
    longitudes.push_back(175);

    vector<int> asignacion_optima = asignar_esquis(alturas, longitudes);

    cout << "Asignación óptima de esquís:" << endl;
    for (int i = 0; i < asignacion_optima.size(); ++i) {
        cout << "Alumno " << i + 1 << ": Esquí " << asignacion_optima[i] + 1 << endl;
    }

    return 0;
}


/*#include <iostream>
#include <cstring>

using namespace std;
const int INF =1e9;
const int N =4;
int soa[N];
int s[N];

void GENERAR(int &suma,int nivel,int longitud,int a[], int l[]){
    s[nivel-1] = longitud;
    suma = suma + abs(a[nivel-1]-l[longitud-1]);
    return;
}

bool SOLUCION(int nivel){
    return (nivel == N);
}

bool CRITERIO(int nivel){
    return nivel < N;
}

void esquis(int a[], int l[]){
    int nivel = 1;
    int longitud = 1;
    int total = INF;
    int suma = 0;
    while(nivel>0){
        GENERAR(suma, nivel,longitud, a,l);
        if((SOLUCION(nivel)) && (suma < total)){
            total = suma;
            for(int i = 0; i < N; i++){
                soa[i] = s[i];
            }
        }
        if(CRITERIO(nivel)){
            nivel = nivel + 1;
        }
        else{
            while(!(MASHERMANOS(nivel)) && (nivel > 0)){
                RETROCEDER()
            }
        }
    }
}

int main(){
    int n = 4;
    int altura[] = {178, 168, 190, 170};
    int longitud[] = {183, 188, 168, 175};
    memset(soa,0,sizeof(soa));
    memset(s,0,sizeof(s));
    esquis(altura, longitud);
    return 0;
}*/