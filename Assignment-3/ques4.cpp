#include <iostream>
using namespace std;

class Stack {
    int size;
    int top;
    char stack[100];
public:
    Stack(int n) {
        size = n;
        top = -1;
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

    char seek() {
        if (top != -1) return stack[top];
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int prec(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    string infix;
    cout << "Enter the expression: ";
    cin >> infix;

    string postfix = "";
    Stack s(infix.length());

    int i = 0;
    int j = 0;

    while (i < infix.length()) {
        if (!isOperator(infix[i])) {
            postfix += infix[i]; 
            i++;
            j++;
        } else {
            // if stack is empty or current operator has higher precedence, push it
            if (s.isEmpty() || prec(infix[i]) > prec(s.seek())) {
                s.push(infix[i]);
                i++;
            } else { 
                // else pop from stack to postfix
                postfix += s.seek();
                s.pop();
                j++;
            }
        }
    }

    // pop remaining operators
    while (!s.isEmpty()) {
        postfix += s.seek();
        s.pop();
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
