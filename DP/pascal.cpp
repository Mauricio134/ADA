#include <iostream>
#include <vector>

using namespace std;

int combinaciones(int n, int p) {
    vector<vector<int>> c(n+1);
    for (int i = 0; i <= n; i++) {
        c[i].resize(p+1);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, p); j++) {
            if ((j == 0 || (j == i)))
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    return c[n][p];
}

int main() {
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        if(j <= i){
          cout << combinaciones(i,j) << " ";
        }else{
          cout << " ";
        }
      }
      cout << endl;
    }

}
