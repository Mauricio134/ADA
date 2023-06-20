#include <iostream>
#include <vector>
using namespace std;

struct Bd {
  int b;
  int d;
  Bd(int b_ = 0, int d_ = 0) {
    b = b_;
    d = d_;
  }
};

void plan_tiempo(vector<int> b, vector<int> &d, vector<Bd> &x) {
  int n = x.size();
  for (int i = 0; i < n; i++) {
    int mejor_beneficio = 0;
    double mejor_por = 0.00;
    for (int j = 0; j < b.size(); j++) {
      double b1 = b[j], d1 = d[j];
      double por = b1 / d1;
      if (por > mejor_por && d[j] >= i + 1) {
        mejor_por = por;
        mejor_beneficio = j;
      }
    }
    x[i] = Bd(b[mejor_beneficio], d[mejor_beneficio]);
    b[mejor_beneficio] = 0;
    d[mejor_beneficio] = 0;
  }
}

int main() {
  vector<int> b = {100, 10, 15, 27};
  vector<int> d = {2,1,2,1};
  vector<Bd> x(2);
  plan_tiempo(b, d, x);
  for (int i = 0; i < x.size(); i++) {
    cout << x[i].b << " " << x[i].d << endl;
  }
}
