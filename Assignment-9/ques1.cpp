#include<iostream>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    int g[20][20]={0};
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u][v]=1;
        g[v][u]=1;
    }

    int start;
    cin>>start;

    int visited[20]={0};
    int q[20],f=0,r=0;

    visited[start]=1;
    q[r++]=start;

    while(f<r){
        int node=q[f++];
        cout<<node<<" ";
        for(int i=0;i<n;i++){
            if(g[node][i]==1 && visited[i]==0){
                visited[i]=1;
                q[r++]=i;
            }
        }
    }
}
