#include <iostream>
using namespace std;

int firstNonRepeat(int arr[], int n){
    int freq[1000];
    for(int i=0;i<1000;i++) freq[i]=0;
    for(int i=0;i<n;i++) freq[arr[i]]++;
    for(int i=0;i<n;i++) if(freq[arr[i]]==1) return arr[i];
    return -1;
}

int main(){
    int arr[]={4,5,1,2,0,4};
    cout<<firstNonRepeat(arr,6);
}
