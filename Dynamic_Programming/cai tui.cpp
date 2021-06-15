#include<bits/stdc++.h>
using namespace std;
struct data{
	int wei,val;
};
int dyn[1002][1002];
int main(){
	int tes;cin>>tes;
	while(tes--){
		int n,m;
		cin>>n>>m;
		data a[n+2];
		for(int i=1;i<=n;i++){
			cin>>a[i].wei;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].val;
		}
		
		memset(dyn,0,sizeof(dyn));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j<a[i].wei){
					dyn[i][j]=dyn[i-1][j];
				}
				else dyn[i][j]=max(dyn[i-1][j],dyn[i-1][j-a[i].wei]+a[i].val);
			}
		}
		cout<<dyn[n][m]<<'\n';
	}
}

