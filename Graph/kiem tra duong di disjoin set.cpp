#include<bits/stdc++.h>
using namespace std;
int used[1003];
vector<int> a[1003];
int v,e;
int BFS(int u){
	vector<int> truoc(v,-1);
	memset(used,0,sizeof(used));
	queue<int> que;
	que.push(u);
	used[u]=1;
	int s,t;
	while(!que.empty()){
		s=que.front();que.pop();
		for(int i=0;i<a[s].size();i++){
			t=a[s][i];
			if(!used[t]){
				que.push(t);
				used[t]=1;
				truoc[t]=s;
			}
			else if(truoc[s]!=t)return 1;
		}
	}
	return 0;
}
int check(){
	memset(used,0,sizeof(used));
	for(int i=1;i<=v;i++){
		if(!used[i]&&BFS(i)){
			return 1;
		}
	}
	return 0;
}
int main(){
	int tes;cin>>tes;int x,y;
	while(tes--){
		cin>>v>>e;
		
		for(int i=1;i<=e;i++){
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		if(check())cout<<"YES";
		else cout<<"NO";
		cout<<'\n';
		for(int i=1;i<=1003;i++)a[i].clear();
	}
}

