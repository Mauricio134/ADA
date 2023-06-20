#include <iostream>
#include <vector>

using namespace std;

void Mochila(double M, vector<int> &b, vector<int> &p, vector<double> &X) {
  int n = b.size();
   X.resize(n, 0.0);
  double pesoAct = 0.0;
  while (pesoAct < M) {
    int mejorObjeto = -1;
    double mejorProporcion = 0.0;
    for (int i = 0; i < n; i++) {
      if (X[i] == 0) {
        double p1 = p[i], b1 = b[i];
        double proporcion = b1/p1;
        if (proporcion > mejorProporcion) {
          mejorProporcion = proporcion;
          mejorObjeto = i;
        }
      }
    }

    if (mejorObjeto == -1) {
      break;
    }

    if (pesoAct + p[mejorObjeto] <= M) {
      double uno = 1.0;
      X[mejorObjeto] = uno;
      double p2 = p[mejorObjeto];
      pesoAct = pesoAct + p[mejorObjeto];
    } else {
      X[mejorObjeto] = 0;
      pesoAct = M;
    }
  }
}

int main() {
  int n = 2;
  double M = 20.5;
  vector<int> P = {1, 100};
  vector<int> B = {2, 190};
  vector<double> X;
  Mochila(M, B, P, X);
  cout << "parte de X:" << endl;
  for (int i = 0; i < n; i++) {
    double a = X[i];
    cout << a << endl;
  }

  return 0;
}

