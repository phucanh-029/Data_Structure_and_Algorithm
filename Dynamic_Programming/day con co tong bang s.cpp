#include<bits/stdc++.h>
using namespace std;
int main(){
	int tes;cin>>tes;
	while(tes--){
		int n,s;
		cin>>n>>s;
		int a[n+1];
		int check[s];
		memset(check,0,sizeof(check));
		check[0]=1;
		for(int i=0;i<n;i++){
			cin>>a[i];
			for(int j=s;j>=a[i];j--){
				if(check[j-a[i]]==1)check[j]=1;
			}
		}
		if(check[s]==1)cout<<"YES\n";
		else cout<<"NO\n";
	}
}

