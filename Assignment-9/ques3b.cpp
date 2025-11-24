#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int g[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];

    int selected[20]={0};
    selected[0]=1;
    int edges=0;
    int cost=0;

    while(edges<n-1){
        int mn=1e9,a=-1,b=-1;
        for(int i=0;i<n;i++){
            if(selected[i]){
                for(int j=0;j<n;j++){
                    if(!selected[j] && g[i][j]!=0 && g[i][j]<mn){
                        mn=g[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        selected[b]=1;
        cost+=mn;
        cout<<a<<" "<<b<<" "<<mn<<endl;
        edges++;
    }

    cout<<cost;
}
