#include <iostream>
using namespace std;

void diagonalMatrix() {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << (i == j ? A[i] : 0) << " ";
        cout << endl;
    }
}

void triDiagonalMatrix() {
    int n;
    cin >> n;
    int A[3*n-2];
    for(int i = 0; i < 3*n-2; i++) cin >> A[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == i-1) cout << A[i-1] << " ";
            else if(j == i) cout << A[n-1 + i] << " ";
            else if(j == i+1) cout << A[2*n-1 + i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void lowerTriangularMatrix() {
    int n;
    cin >> n;
    int A[n*(n+1)/2];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> A[i*(i-1)/2 + j-1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j <= i) cout << A[i*(i-1)/2 + j-1] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void upperTriangularMatrix() {
    int n;
    cin >> n;
    int A[n*(n+1)/2];
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            cin >> A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j >= i) cout << A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void symmetricMatrix() {
    int n;
    cin >> n;
    int A[n*(n+1)/2];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> A[i*(i-1)/2 + j-1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i >= j) cout << A[i*(i-1)/2 + j-1] << " ";
            else cout << A[j*(j-1)/2 + i-1] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    cin >> choice;
    if(choice == 1) diagonalMatrix();
    else if(choice == 2) triDiagonalMatrix();
    else if(choice == 3) lowerTriangularMatrix();
    else if(choice == 4) upperTriangularMatrix();
    else if(choice == 5) symmetricMatrix();
}
