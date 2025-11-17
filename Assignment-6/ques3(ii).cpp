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

    int size(){
        if(!head) return 0;
        int c=0;
        Node* p=head;
        do{
            c++;
            p=p->next;
        }while(p!=head);
        return c;
    }
};

int main(){
    CircularList c;
    c.insertLast(5);
    c.insertLast(15);
    c.insertLast(25);
    cout<<c.size();
}
