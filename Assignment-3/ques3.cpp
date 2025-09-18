#include<iostream>
#include<string>
using namespace std;

class Stack {
    int top;
    int size;
    char stack[100];   
public:
    Stack(int n) {
        top = -1;
        size = n;
    }

    void push(char val) {
        if (top < size - 1) {
            stack[++top] = val;
        } else {
            cout << "overflow\n";
        }
    }

    void pop() {
        if (top != -1) {
            top--;   
        } else {
            cout << "underflow\n";
        }
    }

    bool isEmpty() {
        return top == -1;   
    }
};

int main() {
    string expr;
    cout << "Enter the expression: ";
    cin >> expr;

    int n = expr.length();
    Stack s(n);
    bool balanced = true;

    for (int i = 0; i < n; i++) {
        if (expr[i] == '(') {
            s.push(expr[i]);
        }
        else if (expr[i] == ')') {
            if (s.isEmpty()) {
                balanced = false;  
                break;
            } else {
                s.pop();
            }
        }
    }

    if (!s.isEmpty()) {
        balanced = false;   
    }

    if (balanced) {
        cout << "Expression is balanced";
    } else {
        cout << "Expression is not balanced";
    }

    return 0;
}
