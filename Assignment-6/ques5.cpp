#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x){data=x;next=NULL;}
};

bool isCircular(Node* head){
    if(!head) return false;
    Node* p=head->next;
    while(p && p!=head) p=p->next;
    return p==head;
}

int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    a->next=b;
    b->next=c;
    c->next=a;
    if(isCircular(a)) cout<<"Circular";
    else cout<<"Not Circular";
}
