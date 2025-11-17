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

Node* minNode(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* deleteNode(Node* root,int key){
    if(root==NULL) return root;
    if(key<root->data) root->left=deleteNode(root->left,key);
    else if(key>root->data) root->right=deleteNode(root->right,key);
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        Node* t=minNode(root->right);
        root->data=t->data;
        root->right=deleteNode(root->right,t->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root==NULL) return 0;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return (left>right?left:right)+1;
}

int minDepth(Node* root){
    if(root==NULL) return 0;
    int left=minDepth(root->left);
    int right=minDepth(root->right);
    if(left==0 || right==0) return left+right+1;
    return (left<right?left:right)+1;
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

    root=deleteNode(root,30);

    cout<<maxDepth(root)<<endl;
    cout<<minDepth(root)<<endl;
}
