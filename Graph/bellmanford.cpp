#include<iostream>
#define MAX 100
#define INF 10000000
using namespace std;

class Dothi{
    public:
    int n;
    int A[MAX][MAX];
    int start;
    void getInput();
    void bellmanFord(int start);
};

void Dothi::getInput() {
    cin >> n >> start;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> A[i][j];
            if(A[i][j] == 0) {
                A[i][j] = INF;
            }
        }
    }
}

void Dothi::bellmanFord(int start) {

    // init
    bool reach[n];
    int dist[n];
    int truoc[MAX];
    for(int i = 1; i <= n; i++) {
        reach[i] = false;
        if(A[start][i] != INF) {
            truoc[i] = start;
            reach[i] = true;
        }
        dist[i] = A[start][i];
    }
    truoc[start] = start;
    reach[start] = true;
    dist[start] = 0;
    for(int i = 1; i <= n - 2; i++) {
        for(int u = 1; u <= n; u++)
        if(u != start) {
            for(int v = 1; v <= n; v++) {
                if(A[u][v] != INF && dist[v] > dist[u] + A[u][v]) {
                    dist[v] = dist[u] + A[u][v];
                    truoc[v] = u;
                    reach[v] = true;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(reach[i]) {
            
            cout << "\nK/c " << start << " -> " << i << " = " <<  dist[i] << "; ";
        
            cout << "\t" << i << " <- ";
            int u = truoc[i];
            while(u != start) {
                cout << u <<" <- ";
                u = truoc[u];
            }
            cout << start;
        
        }
        else {
            cout << "\nK/c " << start << " -> " << i << " = " <<  "INF" << ";";
        }
    }
}



int main() {
   Dothi G;
   G.getInput();
   G.bellmanFord(G.start);   
}

