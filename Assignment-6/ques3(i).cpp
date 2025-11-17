#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int x){data=x;prev=next=NULL;}
};

class DoublyList {
public:
    Node* head;
    DoublyList(){head=NULL;}

    void insertLast(int x){
        Node* t=new Node(x);
        if(!head) head=t;
        else{
            Node* p=head;
            while(p->next) p=p->next;
            p->next=t;
            t->prev=p;
        }
    }

    int size(){
        int c=0;
        Node* p=head;
        while(p){c++;p=p->next;}
        return c;
    }
};

int main(){
    DoublyList d;
    d.insertLast(10);
    d.insertLast(20);
    d.insertLast(30);
    cout<<d.size();
}
