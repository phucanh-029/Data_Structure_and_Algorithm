#include<iostream>
using namespace std;
int n,t,a[100][100],used[100];
int x[100];
void readdata(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
}
void init(){
    for(int i=1;i<=n;i++)used[i]=0;
}
void res(){
	cout<<x[n]<<" ";
	for(int i=1;i<n;i++){
		cout<<x[i]<<" ";
	}
	cout<<x[n];
	cout<<'\n';
}
void Hamilton(int k){
    for(int y=1;y<=n;y++){
        if(a[x[k-1]][y]==1&&!used[y]){
            x[k]=y;used[y]=1;
            if(k<n)Hamilton(k+1);
            else if(x[k]==x[0])res();
            used[y]=0;
        }
    }
}
int main(){
	x[0]=1;
    readdata();
    init();
    Hamilton(1);
}
