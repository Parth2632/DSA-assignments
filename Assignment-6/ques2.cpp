#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x){data=x;next=NULL;}
};

class CircularList {
public:
    Node* head;
    CircularList(){head=NULL;}

    void insertLast(int x){
        Node* t=new Node(x);
        if(!head){
            head=t;
            t->next=t;
        }else{
            Node* p=head;
            while(p->next!=head) p=p->next;
            p->next=t;
            t->next=head;
        }
    }

    void display(){
        Node* p=head;
        if(!p) return;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=head);
        cout<<head->data;
    }
};

int main(){
    CircularList c;
    c.insertLast(20);
    c.insertLast(100);
    c.insertLast(40);
    c.insertLast(80);
    c.insertLast(60);
    c.display();
}
