#include<iostream>
using namespace std;

int parent[50];

int findp(int x){
    if(parent[x]==x) return x;
    return parent[x]=findp(parent[x]);
}

void unite(int a,int b){
    a=findp(a);
    b=findp(b);
    if(a!=b) parent[b]=a;
}

int main(){
    int n,e;
    cin>>n>>e;
    int u[50],v[50],w[50];
    for(int i=0;i<e;i++){
        cin>>u[i]>>v[i]>>w[i];
    }

    for(int i=0;i<e-1;i++){
        for(int j=0;j<e-i-1;j++){
            if(w[j]>w[j+1]){
                int t=w[j]; w[j]=w[j+1]; w[j+1]=t;
                t=u[j]; u[j]=u[j+1]; u[j+1]=t;
                t=v[j]; v[j]=v[j+1]; v[j+1]=t;
            }
        }
    }

    for(int i=0;i<n;i++) parent[i]=i;

    int cost=0;
    for(int i=0;i<e;i++){
        if(findp(u[i])!=findp(v[i])){
            unite(u[i],v[i]);
            cost+=w[i];
            cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
        }
    }
    cout<<cost;
}

