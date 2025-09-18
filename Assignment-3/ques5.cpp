#include <iostream>
#include <cctype>
using namespace std;

class Stack {
    int top;
    int size;
    int stack[100];  // store integers
public:
    Stack(int n) {
        size = n;
        top = -1;
    }

    void push(int val) {
        if (top < size - 1) {
            stack[++top] = val;
        } else {
            cout << "overflow\n";
        }
    }

    int pop() {
        if (top != -1) {
            return stack[top--];
        } else {
            cout << "underflow\n";
            return 0; 
        }
    }

    int seek() {
        if (top != -1) return stack[top];
        return 0;
    }
};

int main() {
    string expr;
    cout << "Enter the postfix expression: ";
    cin >> expr;

    Stack s(expr.length());

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (isdigit(c)) {
            s.push(c - '0'); 
        } else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                default: cout << "Unknown operator\n";
            }
        }
    }

    cout << "Result: " << s.pop() << endl;
    return 0;
}
