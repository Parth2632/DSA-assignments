#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){
    Node* t=new Node();
    t->data=x;
    t->left=t->right=NULL;
    return t;
}

bool checkBST(Node* root,int minVal,int maxVal){
    if(root==NULL) return true;
    if(root->data<=minVal || root->data>=maxVal) return false;
    return checkBST(root->left,minVal,root->data) &&
           checkBST(root->right,root->data,maxVal);
}

int main(){
    Node* root=newNode(10);
    root->left=newNode(5);
    root->right=newNode(20);
    root->left->right=newNode(8);

    if(checkBST(root,-1000000,1000000)) cout<<"YES";
    else cout<<"NO";
}
