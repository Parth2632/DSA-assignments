#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int val;
};

void display(Element A[], int n, int r, int c) {
    int k = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(k < n && A[k].row == i && A[k].col == j) {
                cout << A[k].val << " ";
                k++;
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

void transpose(Element A[], int n, int r, int c) {
    Element T[n];
    int k = 0;
    for(int j = 0; j < c; j++)
        for(int i = 0; i < n; i++)
            if(A[i].col == j) {
                T[k].row = A[i].col;
                T[k].col = A[i].row;
                T[k].val = A[i].val;
                k++;
            }
    cout << "Transposed matrix:\n";
    display(T, n, c, r);
}

void addSparse(Element A[], int n1, Element B[], int n2, int r, int c) {
    Element C[n1 + n2];
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2) {
        if(A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
            C[k++] = A[i++];
        else if(B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col))
            C[k++] = B[j++];
        else {
            C[k].row = A[i].row;
            C[k].col = A[i].col;
            C[k].val = A[i].val + B[j].val;
            i++; j++; k++;
        }
    }
    while(i < n1) C[k++] = A[i++];
    while(j < n2) C[k++] = B[j++];
    cout << "Added matrix:\n";
    display(C, k, r, c);
}

void multiplySparse(Element A[], int n1, int r1, int c1, Element B[], int n2, int r2, int c2) {
    if(c1 != r2) {
        cout << "Multiplication not possible\n";
        return;
    }
    int C[r1][c2] = {0};
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n2; j++)
            if(A[i].col == B[j].row)
                C[A[i].row][B[j].col] += A[i].val * B[j].val;
    cout << "Multiplied matrix:\n";
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int r1, c1, n1, r2, c2, n2;
    cin >> r1 >> c1 >> n1;
    Element A[n1];
    for(int i = 0; i < n1; i++)
        cin >> A[i].row >> A[i].col >> A[i].val;

    cin >> r2 >> c2 >> n2;
    Element B[n2];
    for(int i = 0; i < n2; i++)
        cin >> B[i].row >> B[i].col >> B[i].val;

    transpose(A, n1, r1, c1);
    addSparse(A, n1, B, n2, r1, c1);
    multiplySparse(A, n1, r1, c1, B, n2, r2, c2);
}
