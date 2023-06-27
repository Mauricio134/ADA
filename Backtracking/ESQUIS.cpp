//problema 1:
/*#include <iostream>
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
}*/


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Par{
    int s[4];
    int suma;
    Par(int v, int r){
        memset(s,-1,sizeof(s));
        s[0] = v;
        suma = r;
    }
};

void esquis(int a[], int l[], int n){
    int nivel = 1;
    int longitud = 1;
    queue<Par> result;
    while(nivel <= n){
        if(nivel == 1){
            int resp = abs(a[longitud-1]-l[longitud-1]);
            result.push(Par(longitud, resp));
        }
        else{
            for(int limite = 0; limite < n; limite++){
                if(longitud - 1 != limite){
                    result.front().s[nivel-1];
                    
                }
            }
        }
        longitud++;
        if(longitud > n){
            longitud = 1;
            nivel++;
        }
    }
    return;
}

int main(){
    int n = 4;
    int altura[] = {178, 168, 190, 170};
    int longitud[] = {183, 188, 168, 175};

    esquis(altura,longitud,n);
    return 0;
}