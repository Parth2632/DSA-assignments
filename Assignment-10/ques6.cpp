#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int hashSet[1000];

bool check(Node* root){
    if(!root) return false;
    if(hashSet[root->data]==1) return true;
    hashSet[root->data]=1;
    return check(root->left) || check(root->right);
}

int main(){
    for(int i=0;i<1000;i++) hashSet[i]=0;
    Node* a=new Node{5,0,0};
    Node* b=new Node{3,0,0};
    Node* c=new Node{7,0,0};
    Node* d=new Node{3,0,0};
    a->left=b; a->right=c; b->left=d;
    cout<<(check(a)?"Duplicates Found":"No Duplicates");
}
