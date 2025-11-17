#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char x){data=x;prev=next=NULL;}
};

class DoublyList {
public:
    Node* head;
    DoublyList(){head=NULL;}

    void insertLast(char x){
        Node* t=new Node(x);
        if(!head) head=t;
        else{
            Node* p=head;
            while(p->next) p=p->next;
            p->next=t;
            t->prev=p;
        }
    }

    bool isPalindrome(){
        if(!head) return true;
        Node* l=head;
        Node* r=head;
        while(r->next) r=r->next;
        while(l!=r && l->prev!=r){
            if(l->data!=r->data) return false;
            l=l->next;
            r=r->prev;
        }
        return true;
    }
};

int main(){
    DoublyList d;
    d.insertLast('r');
    d.insertLast('a');
    d.insertLast('d');
    d.insertLast('a');
    d.insertLast('r');
    if(d.isPalindrome()) cout<<"Palindrome";
    else cout<<"Not Palindrome";
}
