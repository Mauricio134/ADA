#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void devolverCambio(double P, vector<double> &C, vector<int> &X) {
  double act = 0.0f;
  int j = C.size() - 1;

  double tolerance = 0.0001f;

  for (int i = 0; i < C.size(); i++) {
    X[i] = 0;
  }

  while (abs(act - P) > tolerance) {
    while (C[j] > (P - act) && j > 0) {
      j--;
    }
    if (j == 0 && C[j] > (P - act)) {
      cout << "No existe solución" << endl;
      return;
    }
    int numMone = (P - act) / C[j];
    X[j] = numMone;
    act += C[j] * X[j];
  }
}

int main() {
  double P = 3.89f;
  vector<double> C = {0.01f, 0.10f, 0.20f, 0.50f, 1.00f, 2.00f, 5.00f};
  vector<int> X(C.size());

  devolverCambio(P, C, X);

  cout << "Monedas utilizadas:" << endl;
  for (int i = 0; i < X.size(); i++) {
    if (X[i] > 0) {
      cout << C[i] << " centavos: " << X[i] << endl;
    }
  }
}
