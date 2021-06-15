#include<bits/stdc++.h>
using namespace std;
int n,s,t,a[100][100];
bool used[100];
int truoc[100];
void init(){
    for(int i=1;i<=n;i++){
        used[i]=false;
        truoc[i]=0;
    }
}
void readdata(){
    cin>>n;
    cin>>s>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
}
void DFS(int u){
    stack<int> stk;
    stk.push(u);
    used[u]=true;
    while(!stk.empty()){
        int m=stk.top();
        stk.pop();
        for(int t=1;t<=n;t++){
            if(a[m][t]==1&&!used[t]){
                used[t]=true;
                truoc[t]=m;
                stk.push(m);
                stk.push(t);
                break;
            }
        }
    }
}
void Trace(int dau,int cuoi){
    if(truoc[cuoi]==0)cout<<"no path";
    else{
        cout<<cuoi<<" ";
        int k=cuoi;
        while(truoc[k]!=dau){
            cout<<truoc[k]<<" ";
            k=truoc[k];
        }
        cout<<dau;
	}
}
void BFS(int u){
    queue<int> que;
   
    used[u]=true;
    que.push(u);
    while(!que.empty()){
        int m=que.front();
        que.pop();
        for(int j=1;j<=n;j++){
            if(a[m][j]&&!used[j]){
                truoc[j]=m;
                used[j]=1;
                que.push(j);
            }
        }
    }
}
int main(){
    readdata();
    init();
    DFS(s);
    Trace(s,t);
    cout<<'\n';
    init();
    BFS(s);
    Trace(s,t);
}
