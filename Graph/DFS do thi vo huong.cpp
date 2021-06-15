#include<bits/stdc++.h>
using namespace std;
int v,e,n,used[100];
vector<int> a[100];
void DFS(int u){
	cout<<u<<' ';
	used[u]=1;
	for(int v=0;v<a[u].size();v++){
		if(!used[a[u][v]])DFS(a[u][v]);
	}
}
int main(){
	int tes;cin>>tes;
	while(tes--){
		for(int i=0;i<1001;i++)a[i].clear();
		memset(used,0,sizeof(used));

		cin>>v>>e>>n;int x,y;
		for(int i=1;i<=e;i++){
			
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		DFS(n);
		cout<<'\n';
	}
}

