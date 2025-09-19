#include<iostream>
using namespace std;

class Queue {
    int size;
    int front, rear;
    int queue[100];
public:
    Queue(int n) {
        size = n;
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return rear == size - 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = 0;   // first element
        }
        queue[++rear] = val;
        cout << val << " inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        cout << queue[front] << " removed\n";
        if (front == rear) {
            // last element removed
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element: " << queue[front] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    Queue q(size);

    int choice, val;
    do {
        cout << "\n---- Queue Menu ----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Peek\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.peek();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
