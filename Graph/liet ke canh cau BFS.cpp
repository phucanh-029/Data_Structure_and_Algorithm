#include<bits/stdc++.h>
using namespace std;
int v,e;
vector<int> a[1002];
int used[1002];
vector<int> edg[100000];
int count_bfs_interconnect(){
	int cnt=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=v;i++){
		if(!used[i]){
			queue<int> q;
			cnt++;
			q.push(i);
			used[i]=1;
			while(!q.empty()){
				int x=q.front();
				q.pop();
				for(int j=0;j<a[x].size();j++){
					int y=a[x][j];
					if(!used[y]){
					
						q.push(y);
						used[y]=1;
					}
				}
			}
		}
	}
	return cnt;
}
int bridge(int s,int t){
	int cnt=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<=v;i++){
		if(!used[i]){
			queue<int> q;
			cnt++;
			q.push(i);
			used[i]=1;
			while(!q.empty()){
				int x=q.front();
				q.pop();
				for(int j=0;j<a[x].size();j++){
					int y=a[x][j];
					if((x==s&&y==t)||(y==s&&x==t)||used[y])continue;
					else{
						used[y]=1;
						q.push(x);
						q.push(y);
					}
				}
			}
		}
	}
	return cnt;
}
using namespace std;
int main(){
	int tes;cin>>tes;
	while(tes--){
		for(int i=0;i<1002;i++){
			a[i].clear();
			edg[i].clear();
		}
		cin>>v>>e;
		int x,y;
		for(int i=0;i<e;i++){
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
			edg[i].push_back(x);
			edg[i].push_back(y);
		}
		for(int i=0;i<e;i++){
			if(bridge(edg[i][0],edg[i][1])>count_bfs_interconnect()){
				cout<<edg[i][0]<<" "<<edg[i][1]<<" ";
			}
		}
		cout<<'\n';
	}
}

