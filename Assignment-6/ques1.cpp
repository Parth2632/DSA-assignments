#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x){data=x;prev=next=NULL;}
};

class DoublyList {
public:
    DNode* head;
    DoublyList(){head=NULL;}

    void insertFirst(int x){
        DNode* t=new DNode(x);
        if(!head) head=t;
        else{
            t->next=head;
            head->prev=t;
            head=t;
        }
    }

    void insertLast(int x){
        DNode* t=new DNode(x);
        if(!head) head=t;
        else{
            DNode* p=head;
            while(p->next) p=p->next;
            p->next=t;
            t->prev=p;
        }
    }

    void insertAfter(int key,int x){
        DNode* p=head;
        while(p&&p->data!=key) p=p->next;
        if(!p) return;
        DNode* t=new DNode(x);
        t->next=p->next;
        t->prev=p;
        if(p->next) p->next->prev=t;
        p->next=t;
    }

    void insertBefore(int key,int x){
        if(!head) return;
        if(head->data==key){
            insertFirst(x);
            return;
        }
        DNode* p=head;
        while(p&&p->data!=key) p=p->next;
        if(!p) return;
        DNode* t=new DNode(x);
        t->next=p;
        t->prev=p->prev;
        p->prev->next=t;
        p->prev=t;
    }

    void deleteNode(int key){
        DNode* p=head;
        while(p&&p->data!=key) p=p->next;
        if(!p) return;
        if(p==head) head=head->next;
        if(p->next) p->next->prev=p->prev;
        if(p->prev) p->prev->next=p->next;
        delete p;
    }

    bool search(int key){
        DNode* p=head;
        while(p){
            if(p->data==key) return true;
            p=p->next;
        }
        return false;
    }

    void display(){
        DNode* p=head;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int x){data=x;next=NULL;}
};

class CircularList {
public:
    CNode* head;
    CircularList(){head=NULL;}

    void insertFirst(int x){
        CNode* t=new CNode(x);
        if(!head){
            head=t;
            t->next=t;
        }else{
            CNode* p=head;
            while(p->next!=head) p=p->next;
            t->next=head;
            p->next=t;
            head=t;
        }
    }

    void insertLast(int x){
        CNode* t=new CNode(x);
        if(!head){
            head=t;
            t->next=t;
        } else {
            CNode* p=head;
            while(p->next!=head) p=p->next;
            p->next=t;
            t->next=head;
        }
    }

    void insertAfter(int key,int x){
        if(!head) return;
        CNode* p=head;
        do{
            if(p->data==key){
                CNode* t=new CNode(x);
                t->next=p->next;
                p->next=t;
                return;
            }
            p=p->next;
        }while(p!=head);
    }

    void insertBefore(int key,int x){
        if(!head) return;
        if(head->data==key){
            insertFirst(x);
            return;
        }
        CNode* p=head;
        do{
            if(p->next->data==key){
                CNode* t=new CNode(x);
                t->next=p->next;
                p->next=t;
                return;
            }
            p=p->next;
        }while(p!=head);
    }

    void deleteNode(int key){
        if(!head) return;
        CNode* p=head;
        CNode* q=NULL;
        do{
            if(p->data==key) break;
            q=p;
            p=p->next;
        }while(p!=head);
        if(p->data!=key) return;
        if(p==head && p->next==head){
            head=NULL;
            delete p;
            return;
        }
        if(p==head){
            CNode* last=head;
            while(last->next!=head) last=last->next;
            head=head->next;
            last->next=head;
            delete p;
            return;
        }
        q->next=p->next;
        delete p;
    }

    bool search(int key){
        if(!head) return false;
        CNode* p=head;
        do{
            if(p->data==key) return true;
            p=p->next;
        }while(p!=head);
        return false;
    }

    void display(){
        if(!head) return;
        CNode* p=head;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=head);
        cout<<endl;
    }
};

int main(){
    DoublyList d;
    CircularList c;
    int type,ch,x,key;
    while(cin>>type){
        if(type==1){
            cin>>ch;
            if(ch==1){cin>>x;d.insertFirst(x);}
            else if(ch==2){cin>>x;d.insertLast(x);}
            else if(ch==3){cin>>key>>x;d.insertAfter(key,x);}
            else if(ch==4){cin>>key>>x;d.insertBefore(key,x);}
            else if(ch==5){cin>>key;d.deleteNode(key);}
            else if(ch==6){cin>>key;cout<<d.search(key)<<endl;}
            else if(ch==7) d.display();
        }
        else if(type==2){
            cin>>ch;
            if(ch==1){cin>>x;c.insertFirst(x);}
            else if(ch==2){cin>>x;c.insertLast(x);}
            else if(ch==3){cin>>key>>x;c.insertAfter(key,x);}
            else if(ch==4){cin>>key>>x;c.insertBefore(key,x);}
            else if(ch==5){cin>>key;c.deleteNode(key);}
            else if(ch==6){cin>>key;cout<<c.search(key)<<endl;}
            else if(ch==7) c.display();
        }
    }
}
