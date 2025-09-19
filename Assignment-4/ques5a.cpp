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

// Stack using two queues (optimized)
class StackTwoQueues {
    Queue q1, q2;

public:
    StackTwoQueues(int n = 100) : q1(n), q2(n) {}

    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        // Enqueue new element to q1
        q1.enqueue(x);

        // Move everything back from q2 to q1
        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
    }

    int pop() {
        if (q1.isEmpty()) return -1;
        return q1.dequeue();
    }

    int top() {
        return q1.getFront();
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

// Test program
int main() {
    StackTwoQueues s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;   // 30
    cout << "Pop: " << s.pop() << endl;   // 30
    cout << "Pop: " << s.pop() << endl;   // 20
    cout << "Top: " << s.top() << endl;   // 10
    cout << "Pop: " << s.pop() << endl;   // 10
    cout << "Pop: " << s.pop() << endl;   // -1 (empty)

    return 0;
}
