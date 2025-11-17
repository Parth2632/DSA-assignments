#include <iostream>
using namespace std;

int heapArr[100];
int heapSize=0;

void insertPQ(int x){
    heapArr[heapSize]=x;
    int i=heapSize;
    heapSize++;
    while(i>0 && heapArr[(i-1)/2] < heapArr[i]){
        int t=heapArr[i];
        heapArr[i]=heapArr[(i-1)/2];
        heapArr[(i-1)/2]=t;
        i=(i-1)/2;
    }
}

int deleteMax(){
    if(heapSize==0) return -1;
    int root=heapArr[0];
    heapArr[0]=heapArr[heapSize-1];
    heapSize--;
    int i=0;
    while(true){
        int l=2*i+1, r=2*i+2;
        int largest=i;
        if(l<heapSize && heapArr[l]>heapArr[largest]) largest=l;
        if(r<heapSize && heapArr[r]>heapArr[largest]) largest=r;
        if(largest==i) break;
        int t=heapArr[i];
        heapArr[i]=heapArr[largest];
        heapArr[largest]=t;
        i=largest;
    }
    return root;
}

int main(){
    insertPQ(40);
    insertPQ(10);
    insertPQ(60);
    insertPQ(30);

    cout<<deleteMax()<<endl;
    cout<<deleteMax()<<endl;
    cout<<deleteMax()<<endl;
    cout<<deleteMax()<<endl;
}
