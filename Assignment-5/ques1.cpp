#include<iostream>
using namespace std;

class Node {
public:   
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node *head;
    Node *tail;
public:
    List() {
        head = tail = NULL;
    }

    // (a) Insertion at the beginning
    void push_front(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return; 
        }
        newNode->next = head;
        head = newNode;
    }

    // (b) Insertion at the end
    void push_back(int val){
        Node *newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            tail->next=newNode;
            tail = newNode;
        }
    }

    // (c) Insert before/after a node with specific value
    void insertBefore(int val, int target){
        if(head==NULL){
            cout<<"List is empty!\n";
            return;
        }
        if(head->data==target){ // special case: insert before head
            push_front(val);
            return;
        }
        Node *temp = head;
        while(temp->next!=NULL && temp->next->data!=target){
            temp = temp->next;
        }
        if(temp->next==NULL){
            cout<<"Target not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int val, int target){
        Node *temp = head;
        while(temp!=NULL && temp->data!=target){
            temp = temp->next;
        }
        if(temp==NULL){
            cout<<"Target not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if(temp==tail) tail = newNode;
    }

    // (d) Deletion from the beginning
    void pop_front(){
        if(head==NULL){
            cout<<"Empty list!\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        if(head==NULL) tail=NULL; // list became empty
    }

    // (e) Deletion from the end
    void pop_back(){
        if(head==NULL){
            cout<<"Empty list!\n";
            return;
        }
        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }
        Node *temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // (f) Deletion of a specific node
    void deleteNode(int key){
        if(head==NULL){
            cout<<"Empty list!\n";
            return;
        }
        if(head->data==key){
            pop_front();
            return;
        }
        Node *temp = head;
        while(temp->next!=NULL && temp->next->data!=key){
            temp = temp->next;
        }
        if(temp->next==NULL){
            cout<<"Node "<<key<<" not found!\n";
            return;
        }
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        if(toDelete==tail) tail=temp;
        delete toDelete;
    }

    // (g) Search for a node
    int search(int key){
        Node *temp = head;
        int idx = 0;
        while(temp!=NULL){
            if(temp->data==key)
                return idx;
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // (h) Display all nodes
    void printLL(){
        Node *temp = head;
        if(temp==NULL){
            cout<<"List is empty!\n";
            return;
        }
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};

// ---------------- Menu Driven ----------------
int main(){
    List l;
    int choice, val, target;
    do{
        cout<<"\n--- MENU ---\n";
        cout<<"1. Insert at beginning\n";
        cout<<"2. Insert at end\n";
        cout<<"3. Insert before a value\n";
        cout<<"4. Insert after a value\n";
        cout<<"5. Delete from beginning\n";
        cout<<"6. Delete from end\n";
        cout<<"7. Delete specific node\n";
        cout<<"8. Search a node\n";
        cout<<"9. Display list\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1: cout<<"Enter value: "; cin>>val; l.push_front(val); break;
            case 2: cout<<"Enter value: "; cin>>val; l.push_back(val); break;
            case 3: cout<<"Enter value & target: "; cin>>val>>target; l.insertBefore(val,target); break;
            case 4: cout<<"Enter value & target: "; cin>>val>>target; l.insertAfter(val,target); break;
            case 5: l.pop_front(); break;
            case 6: l.pop_back(); break;
            case 7: cout<<"Enter value to delete: "; cin>>val; l.deleteNode(val); break;
            case 8: cout<<"Enter value to search: "; cin>>val;
                    target=l.search(val);
                    if(target==-1) cout<<"Not found!\n";
                    else cout<<"Found at position "<<target<<"\n";
                    break;
            case 9: l.printLL(); break;
        }
    }while(choice!=0);
}
