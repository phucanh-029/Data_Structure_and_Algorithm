#include<bits/stdc++.h>
using namespace std;
int used[1003];
vector<int> a[1003];

void init(){
	for(int i=1;i<1003;i++)used[i]=0;
}
void BFS(int u){
	init();
	int s,t;
	queue<int> que;
	used[u]=1;
	que.push(u);
	while(!que.empty()){
		s=que.front();que.pop();
		cout<<s<<" ";
		for(int i=0;i<a[s].size();i++){
			int t=a[s][i];
			if(!used[t]){
				que.push(t);
				used[t]=1;
			}
		}
	}
}
int main(){
	int tes;cin>>tes;
	while(tes--){
		int v,e,start;
		cin>>v>>e>>start;
		int x,y;
		for(int i=1;i<=e;i++){
			cin>>x>>y;
			a[x].push_back(y);
		}
		BFS(start);
		cout<<endl;
		for(int i=1;i<=1003;i++)a[i].clear();
	}
}

