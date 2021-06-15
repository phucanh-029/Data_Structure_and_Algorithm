#include<bits/stdc++.h>
using namespace std;
int d[102][25002];
int main(){

		int C,N;
		cin>>C>>N;
		int w[N+3];
		for(int i=1;i<=N;i++)cin>>w[i];

		memset(d,0,sizeof(d));
		for(int i=1;i<=N;i++){
			for(int j=1;j<=C;j++){
				if(j>=w[i])d[i][j]=max(d[i-1][j],d[i-1][j-w[i]]+w[i]);
				else d[i][j]=d[i-1][j];
			}
		}
		cout<<d[N][C]<<'\n';
	
}

