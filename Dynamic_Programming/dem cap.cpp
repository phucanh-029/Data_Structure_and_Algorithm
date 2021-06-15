#include<bits/stdc++.h>
using namespace std;
long long cntcouple(int x,int d[],int n,int b[]){
	if(x==0) return 0;
	if(x==1) return d[0];
	int tmp = upper_bound(b,b+n,x)-b;
	int ans = n-tmp;
	ans+=(d[0]+d[1]);
	if(x==2)ans-=(d[3]+d[4]);//TH: 2,3  2,4
	if(x==3)ans+=d[2];//TH 3,2
	return ans;
}
int main(){
	int tes;cin>>tes;
	while(tes--){
		int m,n;
		cin>>m>>n;
		int a[m],b[n];
		int dem[5]={0};
		for(int i=0;i<m;i++)cin>>a[i];
		for(int i=0;i<n;i++){
			cin>>b[i];
			if(b[i]<5)dem[b[i]]++;
		}
		sort(b,b+n);
		int res=0;
		for(int i=0;i<m;i++){
			res+=cntcouple(a[i],dem,n,b);
		}
		cout<<res<<'\n';
	}
}

