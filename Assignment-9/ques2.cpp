#include<iostream>
using namespace std;

int g[20][20];
int visited[20];
int n;

void dfs(int s){
    visited[s]=1;
    cout<<s<<" ";
    for(int i=0;i<n;i++){
        if(g[s][i]==1 && visited[i]==0){
            dfs(i);
        }
    }
}

int main(){
    int e;
    cin>>n>>e;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]=0;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u][v]=1;
        g[v][u]=1;
    }

    int start;
    cin>>start;

    for(int i=0;i<n;i++) visited[i]=0;

    dfs(start);
}
