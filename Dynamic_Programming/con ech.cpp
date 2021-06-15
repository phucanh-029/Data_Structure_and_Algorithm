#include<bits/stdc++.h>
using namespace std;
int main(){
	int tes;cin>>tes;
	while(tes--){
		int n;
		cin>>n;
		long long socach[100];
		memset(socach,0,sizeof(socach));
		socach[1]=1;socach[2]=2;socach[3]=4;
		for(int i=4;i<=n;i++){
			socach[i]=socach[i-1]+socach[i-2]+socach[i-3];
		}
		cout<<socach[n]<<'\n';
	}
}

