#include <iostream>
#define MAX 100
using namespace std;
struct  edg{
    int     h, id, n1, n2;
};
class   dothi{
    int     n, a[MAX][MAX], ne, atree[MAX][MAX], dh;
    edg     edglst[MAX], edgtree[MAX];
    public:
    bool    chuaxet[MAX];
    void    readdata();
    void    init();
    void    dfs(int u);
    void    bubblesort();
    void    kruskal();
};
void    dothi::readdata(){
    cin >> n;   ne=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){            
            cin >> a[i][j];
            if((a[i][j]>0)&&(i<j)){         
                ne++;
                edglst[ne].h=a[i][j];   edglst[ne].id=ne;
                edglst[ne].n1=i;        edglst[ne].n2=j;    }
        }
}
void    dothi::init(){    for(int i=1; i<=n; i++)   chuaxet[i]=true;    }
void    dothi::dfs(int u){
    chuaxet[u]=false;
    for(int i=1; i<=n; i++)
        if((atree[u][i]==1)&&(chuaxet[i]==true))    dfs(i);
}
void    dothi::bubblesort(){
    for(int i=1; i<=ne; i++)
        for(int j=ne; j>=i+1; j--)
            if(edglst[j].h<edglst[j-1].h){
                edg tmp=edglst[j-1];    edglst[j-1]=edglst[j];  edglst[j]=tmp;
            }
}
void    dothi::kruskal(){
    int net=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) atree[i][j]=0;
    dh=0;
    bubblesort();
    for(int i=1; i<=ne; i++){
        int n1=edglst[i].n1;    int n2=edglst[i].n2;
        init(); dfs(n1);
        if(chuaxet[n2]==true){//khong tao chu trinh, bo sung canh vao cay
            dh+=edglst[i].h; net++; edgtree[net].n1=n1; edgtree[net].n2=n2;
            atree[n1][n2]=1;  atree[n2][n1]=1;
        }
    }
    //cout << net;
    if(net==n-1){
        cout << " dH = " << dh << endl;
        for(int i=1; i<=net; i++)  
            cout << edgtree[i].n1 << "  " << edgtree[i].n2 << endl;
    }
}
int main(){
    dothi       g;  g.readdata();   g.kruskal();
}
