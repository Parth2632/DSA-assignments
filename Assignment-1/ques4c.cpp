// Find the Transpose of a Matrix

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns of the matrix: ";
    cin >> m >> n;

    int A[m][n], T[n][m];

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {       
        for (int j = 0; j < m; j++) {   
            T[i][j] = A[j][i];
        }
    }

    cout << "Transpose of the Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
