#include<bits/stdc++.h>
using namespace std;
int n,a[100][100],ne,dh,used[100],atree[100][100];
struct edg{
	int h,id,n1,n2;
};
edg edglist[100],edgtree[100];
void readdata(){
	cin>>n;
	ne=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		cin>>a[i][j];
		if(a[i][j]>0&&i<j){
			ne++;
			edglist[ne].h=a[i][j];
			edglist[ne].id=ne;
			edglist[ne].n1=i;
			edglist[ne].n2=j;}
		}
	}
}
void init(){
	for(int i=1;i<=n;i++)used[i]=0;
}
void dfs(int u){
	used[u]=true;
	for(int i=1;i<=n;i++){
		if(atree[u][i]==1&&!used[i])dfs(i);
	}
}
void bubbleSort(){
	for(int i=1;i<=ne;i++){
		for(int j=ne;j>=i+1;j--){
			if(edglist[j-1].h>edglist[j].h){
				swap(edglist[j-1],edglist[j]);
			}
		}
	}
}
void Kruskal(){
	int net=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)atree[i][j]=0;
	}
	dh=0;
	bubbleSort();
	for(int i=1;i<=ne;i++){
		int n1=edglist[i].n1;
		int n2=edglist[i].n2;
		init();dfs(n1);
		if(!used[n2]){
			dh+=edglist[i].h;net++;
			edgtree[net].n1=n1;
			edgtree[net].n2=n2;
			atree[n1][n2]=1;
			atree[n2][n1]=1;
		}
	}
	if(net==n-1){
		cout<<dh<<'\n';
		for(int i=1;i<=net;i++)cout<<edgtree[i].n1<<" "<<edgtree[i].n2<<endl;
	}
}
int main(){
	readdata();
	Kruskal();
}

