#include<bits/stdc++.h>
using namespace std;

int main(){
	int tes;cin>>tes;
	while(tes--){
		int v,e;
		cin>>v>>e;
		vector<int> ke[v+1];
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
			ke[a].push_back(b);
			ke[b].push_back(a);
		}
		for(int i=1;i<=v;i++){
			sort(ke[i].begin(),ke[i].end());
		}
		for(int i=1;i<=v;i++){
			cout<<i<<": ";
			for(int j:ke[i])cout<<j<<" ";
			cout<<endl;
		}
	}
}

