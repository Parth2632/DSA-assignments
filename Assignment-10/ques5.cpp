#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

bool hasCycle(Node* head){
    Node* hash[1000];
    for(int i=0;i<1000;i++) hash[i]=NULL;
    while(head){
        for(int i=0;i<1000;i++){
            if(hash[i]==head) return true;
            if(hash[i]==NULL){ hash[i]=head; break; }
        }
        head=head->next;
    }
    return false;
}

int main(){
    Node* a=new Node{1,0};
    Node* b=new Node{2,0};
    Node* c=new Node{3,0};
    Node* d=new Node{4,0};
    a->next=b; b->next=c; c->next=d; d->next=b;
    cout<<(hasCycle(a)?"true":"false");
}
