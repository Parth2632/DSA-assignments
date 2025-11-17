#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insertNode(Node* root,int val){
    if(root==NULL){
        Node* t=new Node();
        t->data=val;
        t->left=t->right=NULL;
        return t;
    }
    if(val<root->data) root->left=insertNode(root->left,val);
    else if(val>root->data) root->right=insertNode(root->right,val);
    return root;
}

Node* searchRec(Node* root,int key){
    if(root==NULL || root->data==key) return root;
    if(key<root->data) return searchRec(root->left,key);
    return searchRec(root->right,key);
}

Node* searchNonRec(Node* root,int key){
    while(root){
        if(key==root->data) return root;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    return NULL;
}

Node* minNode(Node* root){
    while(root && root->left) root=root->left;
    return root;
}

Node* maxNode(Node* root){
    while(root && root->right) root=root->right;
    return root;
}

Node* successor(Node* root, Node* x){
    if(x->right) return minNode(x->right);
    Node* succ=NULL;
    while(root){
        if(x->data < root->data){
            succ=root;
            root=root->left;
        } else if(x->data > root->data){
            root=root->right;
        } else break;
    }
    return succ;
}

Node* predecessor(Node* root, Node* x){
    if(x->left) return maxNode(x->left);
    Node* pred=NULL;
    while(root){
        if(x->data > root->data){
            pred=root;
            root=root->right;
        } else if(x->data < root->data){
            root=root->left;
        } else break;
    }
    return pred;
}

int main(){
    Node* root=NULL;
    root=insertNode(root,50);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,40);
    insertNode(root,70);
    insertNode(root,60);
    insertNode(root,80);

    Node* s=searchRec(root,40);
    Node* m=minNode(root);
    Node* M=maxNode(root);
    Node* suc=successor(root,s);
    Node* pre=predecessor(root,s);

    if(s) cout<<s->data<<endl;
    if(m) cout<<m->data<<endl;
    if(M) cout<<M->data<<endl;
    if(suc) cout<<suc->data<<endl;
    if(pre) cout<<pre->data<<endl;
}
