#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> LCS(vector<char> X, vector<char> Y) {
  vector<vector<int>> c(X.size() + 1);
  for (int i = 0; i < X.size() + 1; i++) {
    c[i].resize(Y.size() + 1);
  }
  for (int i = 0; i <= X.size(); i++)
    c[i][0] = 0;
  for (int j = 1; j <= Y.size(); j++)
    c[0][j] = 0;

  for (int i = 1; i <= X.size(); i++) {
    for (int j = 1; j <= Y.size(); j++) {
      if (X[i - 1] == Y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
      } else {
        c[i][j] = max(c[i - 1][j], c[i][j - 1]);
      }
    }
  }
  return c;
}

string find_Sequence(vector<char> X, vector<char> Y, vector<vector<int>> c) {
  string word;
  int i = X.size();
  int j = Y.size();
  while (i > 0 && j > 0) {
    if (X[i - 1] == Y[j - 1]) {
      word += X[i - 1];
      i--;
      j--;
    } else {
      if (c[i - 1][j] >= c[i][j - 1])
        i--;
      else
        j--;
    }
  }
  return word;
}

int main() {
  vector<char> X = {'A', 'B', 'C', 'B'};
  vector<char> Y = {'B', 'D', 'C', 'A', 'B'};
  vector<vector<int>> c = LCS(X, Y);
  for (int i = 0; i <= X.size(); i++) {
    for (int j = 0; j <= Y.size(); j++) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
  string word = find_Sequence(X, Y, c);
  cout << word << endl;
}
