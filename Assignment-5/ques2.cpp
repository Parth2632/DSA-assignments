#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
public:
    List() { head = NULL; }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    void deleteAllOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->data == key) {
                count++;

                if (prev == NULL) {
                    // deleting head
                    head = temp->next;
                    delete temp;
                    temp = head;
                } else {
                    // deleting middle or last node
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        cout << "Count: " << count << endl;
        printList();
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(1);
    l.push_back(2);
    l.push_back(1);
    l.push_back(3);
    l.push_back(1);

    cout << "Original List: ";
    l.printList();

    l.deleteAllOccurrences(1);  // key = 1
}
