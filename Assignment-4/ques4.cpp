#include <iostream>
using namespace std;

class Queue {
    char arr[100];
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

    void enqueue(char ch) {
        if (!isFull()) {
            arr[++rear] = ch;
        } else {
            cout << "Queue is full\n";
        }
    }

    char dequeue() {
        if (!isEmpty()) {
            return arr[front++];
        } else {
            return '\0';
        }
    }

    char getFront() {
        if (!isEmpty()) return arr[front];
        return '\0';
    }
};

void firstNonRepeating(char str[], int n) {
    Queue q(n);
    int freq[256] = {0};  

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        if (ch == ' ') continue; 

        q.enqueue(ch);

        freq[(int)ch]++;

        // Step 3: remove repeating characters from front
        while (!q.isEmpty() && freq[(int)q.getFront()] > 1) {
            q.dequeue();
        }

        // Step 4: print first non-repeating
        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.getFront() << " ";
    }
    cout << endl;
}

int main() {
    char input[] = "a a b c";  // sample input
    int n = sizeof(input)/sizeof(input[0]) - 1; // exclude null char

    cout << "Input: " << input << endl;
    cout << "Output: ";
    firstNonRepeating(input, n);

    return 0;
}
