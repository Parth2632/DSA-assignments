#include <iostream>
using namespace std;

// Array-based Queue
class Queue {
    int arr[100];
    int front, rear, size;

public:
    Queue(int n = 100) {
        size = n;
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return (front > rear);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(int val) {
        if (!isFull()) arr[++rear] = val;
        else cout << "Queue is full\n";
    }

    int dequeue() {
        if (!isEmpty()) return arr[front++];
        return -1;
    }

    int getFront() {
        if (!isEmpty()) return arr[front];
        return -1;
    }

    int getSize() {
        return rear - front + 1;
    }
};

// Stack using one queue
class StackOneQueue {
    Queue q;

public:
    // Normal constructor style
    StackOneQueue(int n = 100) {
        q = Queue(n);
    }

    void push(int x) {
        int n = q.getSize();
        q.enqueue(x);

        // Rotate previous elements to back
        for (int i = 0; i < n; i++) {
            q.enqueue(q.dequeue());
        }
    }

    int pop() {
        if (q.isEmpty()) return -1;
        return q.dequeue();
    }

    int top() {
        return q.getFront();
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};

// Test program
int main() {
    StackOneQueue s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;   // 30
    cout << "Pop: " << s.pop() << endl;   // 30
    cout << "Pop: " << s.pop() << endl;   // 20
    cout << "Top: " << s.top() << endl;   // 10
    cout << "Pop: " << s.pop() << endl;   // 10
    cout << "Pop: " << s.pop() << endl;   // -1

    return 0;
}
