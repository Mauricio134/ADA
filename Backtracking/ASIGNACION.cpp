#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 3;

int B[N][N] = {
    {4, 9, 1},
    {7, 2, 3},
    {6,3, 5}
};

vector<int> best_assignment; 
int best_benefit = INT_MIN; 

vector<int> current_assignment; 
vector<bool> used(N, false); 

void backtrack(int col, int benefit) {
    if (col == N) {
        if (benefit > best_benefit) {
            best_benefit = benefit;
            best_assignment = current_assignment;
        }
        return;
    }

    for (int row = 0; row < N; row++) {
        if (!used[row]) {
            used[row] = true;
            current_assignment[col] = row;
            backtrack(col + 1, benefit + B[row][col]);
            used[row] = false;
        }
    }
}

int main() {
    current_assignment.resize(N);

    backtrack(0, 0);

    cout << "Mejor asignación: ";
    for (int i = 0; i < N; i++) {
        cout << best_assignment[i] + 1 << " ";
    }
    cout << endl;

    cout << "Beneficio máximo: " << best_benefit << endl;

    return 0;
}
