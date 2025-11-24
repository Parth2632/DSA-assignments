#include <iostream>
using namespace std;

int main(){
    int A[]={1,2,3,4};
    int B[]={3,4,5,6};
    int hash[1000];
    for(int i=0;i<1000;i++) hash[i]=0;
    for(int i=0;i<4;i++) hash[A[i]]=1;
    for(int i=0;i<4;i++) if(hash[B[i]]==1) cout<<B[i]<<" ";
}
