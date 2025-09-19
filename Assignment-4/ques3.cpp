#include <iostream>
using namespace std;

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
        if (!isFull()) {
            arr[++rear] = val;
        } else {
            cout << "Queue is full\n";
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            return arr[front++];
        } else {
            cout << "Queue is empty\n";
            return -1;
        }
    }

    int getSize() {
        return (rear - front + 1);
    }

    int getFront() {
        if (!isEmpty()) return arr[front];
        return -1;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // ----------- Interleave Function ------------
    void interleave() {
        int n = getSize();
        if (n % 2 != 0) {
            cout << "Queue has odd number of elements!\n";
            return;
        }

        int half = n / 2;
        Queue q2(size);

        // Step 1: Move first half into q2
        for (int i = 0; i < half; i++) {
            q2.enqueue(dequeue());
        }

        // Step 2: Interleave q2 and this queue
        while (!q2.isEmpty()) {
            enqueue(q2.dequeue());  // first half element
            enqueue(dequeue());     // second half element
        }
    }
};

int main() {
    Queue q(20);

    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        q.enqueue(arr[i]);
    }

    cout << "Original Queue: ";
    q.display();

    q.interleave();

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
