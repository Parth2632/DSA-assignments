#include <iostream>
using namespace std;

class Stack {
    int stack[100];
    int top;
    int size;

public:
    Stack(int n) {
        size = n;
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
        } else {
            stack[++top] = val;
            cout << val << " pushed into stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
        } else {
            cout << stack[top--] << " popped from stack.\n";
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Top element: " << stack[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter size of stack: ";
    cin >> n;

    Stack arr(n);

    int choice = -1, val;
    while (choice != 0) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                arr.push(val);
                break;

            case 2:
                arr.pop();
                break;

            case 3:
                arr.peek();
                break;

            case 4:
                arr.display();
                break;

            case 5:
                if (arr.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;

            case 6:
                if (arr.isFull())
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
