// Write a program to find sum of every row and every column in a two-dimensional
// array.


#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns of the matrix: ";
    cin >> m >> n;

    int A[m][n];

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Row sums:\n";
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += A[i][j];
        }
        cout << "Row " << i << " sum = " << rowSum << endl;
    }

    cout << "Column sums:\n";
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += A[i][j];
        }
        cout << "Column " << j << " sum = " << colSum << endl;
    }

    return 0;
}
