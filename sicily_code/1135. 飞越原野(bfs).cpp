#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int row, col, dis;
int to[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char mp[101][101];
int vis[101][101][101];

struct node {
    int x, y;
    int c, d;
    node(int X = 0, int Y = 0, int C = 0, int D = 0) {
        x = X, y = Y;
        c = C, d = D;
    }
};

bool in(int x, int y) {
    return (x >= 1 && x <= row) && (y >= 1 && y <= col);
}

int main() {
    cin >> row >> col >> dis;
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++)
            cin >> mp[i][j];
    
    int jud = 0;
    memset(vis, false, sizeof(vis));
    queue<node> q;
    q.push(node(1, 1, 0, dis));
    while(!q.empty()) {
        node tmp = q.front();
        q.pop();          
        for(int i = 0; i <= tmp.d && !jud; i++) { 
            for(int j = 0; j < 4; j++) { 
                int index = i-1;
                int tmpx = tmp.x + to[j][0];
                int tmpy = tmp.y + to[j][1];
                while(index > 0) {
                    tmpx += to[j][0];
                    tmpy += to[j][1];
                    index--;
                }
                if(in(tmpx, tmpy) && !vis[tmpx][tmpy][tmp.d-i] && mp[tmpx][tmpy] == 'P') {
                    if(tmpx == row && tmpy == col) {
                        jud = 1;
                        cout << tmp.c + 1 << endl;
                        break;
                    }
                    q.push(node(tmpx, tmpy, tmp.c+1, tmp.d-i));
                    vis[tmpx][tmpy][tmp.d-i] = true;
                }
            }
        }
        if(jud) break;
    }
    if(!jud) cout << "impossible\n";
}
