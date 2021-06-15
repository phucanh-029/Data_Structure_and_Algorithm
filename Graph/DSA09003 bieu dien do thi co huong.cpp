#include<bits/stdc++.h>
using namespace std;
int main(){
	int tes;cin>>tes;
	while(tes--){
		int v,e;
		cin>>v>>e;
		vector<int> ke[v+1];
		int x,y;
		for(int i=1;i<=e;i++){
			cin>>x>>y;
			ke[x].push_back(y);
		}
		for(int i=1;i<=v;i++){
			cout<<i<<": ";
			for(int j=0;j<ke[i].size();j++){
				cout<<ke[i][j]<<" ";
			}
			cout<<'\n';
		}
	}
}

