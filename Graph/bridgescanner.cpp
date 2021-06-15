
#include<iostream>

using namespace std;
class Dothi {
    int n;
    int A[100][100];
    public:
    bool used[100];
    void readData();
    void init();
    void recurDFS(int u);
    void duyetcau();
};

void Dothi::readData() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n ;j++) cin >> A[i][j];
    }
}

void Dothi::init(){
    for(int i = 1; i <= n; i++) {
        used[i] = false;
    }
}

void Dothi::recurDFS(int u) {
    used[u] = true;
    for(int v = 1; v <= n ; v++) {
        if(!used[v] && A[u][v] == 1) {
            recurDFS(v);
        }
    }
}

void Dothi::duyetcau() {
    // init
    init();
     for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n ;j++){
            if(A[i][j] == 1) {
                A[i][j] = 0; A[j][i] = 0; // xoa canh
                recurDFS(1);
                for(int k = 1; k <= n; k++) {
                    if(!used[k]) {
                        cout << " " << i << " " << j <<  "\n";
                        break;
                    }
                }
                A[i][j] = 1; A[j][i] = 1;
                init();
            }
        }
    }
}

int main() {
    Dothi G;
    G.readData();
    G.init();
    G.duyetcau();
}

