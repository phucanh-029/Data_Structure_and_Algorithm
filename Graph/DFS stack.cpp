#include<bits/stdc++.h>
using namespace std;
class Graph{
    int n;
    int a[100][100];
    public:
    bool unused[100];
    void readdata();
    void init();
    void loopDFS(int u);
};
void Graph::readdata(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
}
void Graph::init(){
    for(int i=1;i<=n;i++)unused[i]=true;
}
void Graph::loopDFS(int u){
    stack<int> stk;
    cout<<" "<<u;
    unused[u]=false;
    stk.push(u);
    while(!stk.empty()){
        int s=stk.top();
        stk.pop();
        for(int t=1;t<=n;t++)
            if(a[s][t]&&(unused[t]==true)){
                cout<<" "<<t;
                unused[t]=false;
                stk.push(s);
                stk.push(t);
                break;
            }
    }
}
int main(){
    Graph G;
    G.readdata();
    G.init();
    G.loopDFS(1);
}
