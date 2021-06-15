#include<bits/stdc++.h>
using namespace std;
int n,dh,nex,start,a[100][100],tree[100][100];

struct edge{
	int dau,cuoi,val,id;
};
edge edgelist[100],edgetree[100];
void readdata(){
	cin>>n>>start;
	nex=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]>0&&i<j){
				nex++;
				edgelist[nex].val=a[i][j];
				edgelist[nex].dau=i;
				edgelist[nex].cuoi=j;
			}
		}
	}
}
void bubble(){
	for(int i=1;i<nex;i++){
		for(int j=nex;j>i;j--){
			if(edgelist[j].val<edgelist[j-1].val)
			swap(edgelist[j],edgelist[j-1]);
		}
	}
}
int used[100];
void init(){
	for(int i=1;i<=n;i++)used[i]=0;
}
void dfs(int u){
	used[u]=1;
	for(int i=1;i<=n;i++){
		if(!used[i]&&tree[u][i]==1)dfs(i);
	}
}
void Prim(int s){
	int net=0;
	dh=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)tree[i][j]=tree[j][i]=0;
	}
	bubble();
	while(net!=n-1){
		for(int i=1;i<=nex;i++){
			init();
			dfs(start);
			int dau=edgelist[i].dau;
			int cuoi=edgelist[i].cuoi;
			if(((!used[dau]&&!used[cuoi])==0)&&((!used[dau]||!used[cuoi])==1)){
				net++;
				dh+=edgelist[i].val;
				edgetree[net].dau=dau;
				edgetree[net].cuoi =cuoi;
				tree[dau][cuoi]=1;
				tree[cuoi][dau]=1;
				break;
			}
		}
	}
	cout<<"dH = "<<dh<<'\n';
	for(int i=1;i<=net;i++)cout<<edgetree[i].dau<<" "<<edgetree[i].cuoi<<'\n';
}
int main(){
	readdata();
	Prim(start);
}
