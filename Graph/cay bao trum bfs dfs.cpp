#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int n,start,a[100][100];
int used[100];
void init(){
    for(int i=1;i<=n;i++)used[i]=0;
}
void nhap(){
    cin>>n>>start;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
}
void DFS(int u){
	stack<int> stk;
	used[u]=1;
	stk.push(u);
	while(!stk.empty()){
		int s=stk.top();
		for(int t=1;t<=n;t++){
			if(a[s][t] && !used[t]){
				cout<<s<<" "<<t<<'\n';
				stk.push(s);
				stk.push(t);
				used[t]=0;
				break;
			}
		}
	}
}
void QueueBFS(int u){
    queue<int> que;
    unused[u]=false;
    que.push(u);
    while(!que.empty()){
        int s=que.front();
        que.pop();
        for(int t=1;t<=n;t++){
            if(a[s][t]&&unused[t]){
                cout<<s<<" "<<t<<'\n';
                unused[t]=0;
                que.push(t);
                cout<<endl;
            }
        }
    }
}
int main(){
    nhap();
    init();
    cout<<"DFS tree\n";
    DFS(start);
    init();
    cout<<"BFS tree\n";
    QueueBFS(start);
}
