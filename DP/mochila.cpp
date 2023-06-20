#include <iostream>
#include <vector>

using namespace std;

void Mochila(int M, int n, vector<int> &b, vector<int> &p, int **V,
             vector<int> &X) {
  for (int i = 0; i <= n; i++) {
    V[i][0] = 0;
  }
  for (int i = 0; i <= M; i++) {
    V[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= M; j++) {
      if (p[i - 1] <= j)
        V[i][j] = max(V[i - 1][j], b[i - 1] + V[i - 1][j - p[i - 1]]);
      else
        V[i][j] = V[i - 1][j];
    }
  }

  int j = M;
  for (int i = n; i > 0; i--) {
    if (V[i][j] == V[i - 1][j]) {
      X[i - 1] = 0;
    } else {
      X[i - 1] = 1;
      j = j - p[i - 1];
    }
  }
}

int main() {
  int n = 3;
  int M = 6;
  vector<int> P = {2, 3, 4};
  vector<int> B = {1, 2, 5};
  int **V = new int *[n + 1];
  for (int i = 0; i < n + 1; i++) {
    V[i] = new int[M + 1];
  }
  vector<int> X(3);
  Mochila(M, n, B, P, V, X);
  for (int i = 0; i < n; i++) {
    cout << X[i] << endl;
  }
  return 0;
}

