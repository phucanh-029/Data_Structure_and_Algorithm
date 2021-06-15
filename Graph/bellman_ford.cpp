#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
int n,S,a[100][100],used[100],truoc[100],bf[100];
void readdata(){
    cin>>n>>S;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(i==j)a[i][j]=0;
            if(a[i][j]==0)a[i][j]=INF;
        }
    }
}
void init(int s){
    for(int i=1;i<=n;i++){
        bf[i]=a[s][i];
		used[i]=0;
        truoc[i]=s;
    }
    bf[s]=0;
    used[s]=1;
}
int bellman_ford(int s){
    init(s);
    for(int i=1;i<=n-2;i++){
        for(int z=1;z<=n;z++){
            if(z!=s){
            	for(int k=1;k<=n;k++){
            		if(bf[z]>bf[k]+a[k][z]){
            			bf[z]=bf[k]+a[k][z];
            			truoc[z]=k;
            			used[k]=1;
					}
				}
            }
        }
    }
    for(int t=1;t<=n;t++){
        if(!used[t]){
            cout<<"K/c "<<s<<" -> "<<t<<"= INF;\n";
        }
        else{
            cout<<"\nK/c "<<s<<" -> "<<t<<" = "<<bf[t]<<"; ";
            cout<<"   "<<t<<" <- ";
            int truoct=truoc[t];
            while(truoct!=s){
                cout<<truoct<<" <- ";
                truoct=truoc[truoct];
            }
            cout<<s<<'\n';
        }
    }
}
int main(){
    readdata();
    bellman_ford(S);
}


