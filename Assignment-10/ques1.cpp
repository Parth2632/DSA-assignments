#include <iostream>
using namespace std;

bool containsDuplicate(int nums[], int n) {
    int hash[1000];
    for(int i=0;i<1000;i++) hash[i]=0;
    for(int i=0;i<n;i++){
        int x = nums[i];
        if(hash[x]==1) return true;
        hash[x]=1;
    }
    return false;
}

int main(){
    int nums[]={1,2,3,1};
    cout<<(containsDuplicate(nums,4)?"true":"false");
}
