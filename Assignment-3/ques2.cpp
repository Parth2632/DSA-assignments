#include <iostream>
#include <string>
using namespace std;

class Stack {
    int top;
    int size;
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
            cout << "Overflow\n";
        }
    }

    char pop() {
        if (top != -1) {
            return stack[top--];
        } else {
            cout << "Underflow\n";
            return '\0'; 
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int n = str.length();
    Stack s(n);

    // Push all characters into stack
    for (int i = 0; i < n; i++) {
        s.push(str[i]);
    }

    // Pop characters to get reversed string
    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}
