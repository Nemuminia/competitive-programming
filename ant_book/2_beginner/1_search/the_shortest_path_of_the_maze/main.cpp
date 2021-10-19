#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> P;

#define MAX_SIZE 100

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    int n, m;
    char maze[MAX_SIZE][MAX_SIZE];
    int start_x, start_y;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
        }
    }

    queue<P> q;
    q.push(P(start_x, start_y));
    int turn[MAX_SIZE][MAX_SIZE] = { 0 };
    bool goal_flag = false;
    int ans = -1;

    while (q.size() > 0) {
        P p = q.front();
        q.pop();

        int px = p.first;
        int py = p.second;

        for (int i = 0; i < 4; i++) {
            if ((px + dx[i] < 0 || px + dx[i] >= n) || (py + dy[i] < 0 || py + dy[i] >= m)) {
                continue;
            } else if (maze[px + dx[i]][py + dy[i]] == '.') {
                maze[px + dx[i]][py + dy[i]] == '-';
                turn[px + dx[i]][py + dy[i]] = turn[px][py] + 1;
                q.push(P(px + dx[i], py + dy[i]));
            } else if (maze[px + dx[i]][py + dy[i]] == 'G') {
                ans = turn[px][py] + 1;
                goal_flag = true;
                break;
            }
        }

        if (goal_flag) break;
    }

    cout << ans << endl;

    return 0;
}