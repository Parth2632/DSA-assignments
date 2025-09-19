#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Check if empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if full
    bool isFull() {
        return ((rear + 1) % size == front);
    }

    // Insert element
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot insert " << val << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        cout << val << " inserted into queue." << endl;
    }

    // Delete element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Nothing to delete." << endl;
            return;
        }
        int removed = arr[front];
        if (front == rear) {
            // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        cout << "Deleted element: " << removed << endl;
    }

    // Get front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int n, choice, val;
    cout << "Enter size of Circular Queue: ";
    cin >> n;

    CircularQueue q(n);

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if (q.isEmpty())
                    cout << "Queue is EMPTY.\n";
                else
                    cout << "Queue is NOT empty.\n";
                break;
            case 6:
                if (q.isFull())
                    cout << "Queue is FULL.\n";
                else
                    cout << "Queue is NOT full.\n";
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
