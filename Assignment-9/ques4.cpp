#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int g[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];

    int src;
    cin>>src;

    int dist[20],vis[20];
    for(int i=0;i<n;i++){
        dist[i]=1e9;
        vis[i]=0;
    }
    dist[src]=0;

    for(int c=0;c<n-1;c++){
        int mn=1e9,u=-1;
        for(int i=0;i<n;i++){
            if(!vis[i] && dist[i]<mn){
                mn=dist[i];
                u=i;
            }
        }
        vis[u]=1;

        for(int v=0;v<n;v++){
            if(!vis[v] && g[u][v]!=0 && dist[u]+g[u][v] < dist[v]){
                dist[v]=dist[u]+g[u][v];
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}
