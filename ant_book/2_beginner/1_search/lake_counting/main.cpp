#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100

int n, m;
char garden[MAX_SIZE][MAX_SIZE];

// 移動先の8方向の座標を横軸・縦軸を表す配列で表現
int dir_x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dir_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs(int x, int y){
    // 確認済みの座標は塗り替え
    garden[x][y] = '-';
    for(int i = 0; i < 8; i++) {
        // 端からはみ出ないようにチェック
        if(x + dir_x[i] < 0 || x + dir_x[i] >= n || y + dir_y[i] < 0 || y + dir_y[i] >= m) continue;
        if(garden[x + dir_x[i]][y + dir_y[i]] == 'W') {
            dfs(x + dir_x[i], y + dir_y[i]);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> garden[i][j];
        }
    }
    
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(garden[i][j] == 'W') {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}