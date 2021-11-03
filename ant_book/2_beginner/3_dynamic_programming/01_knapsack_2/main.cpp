#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_W 10001

int main(){
    int n;
    int w[MAX_N], v[MAX_N];
    int W;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    // i番目までの品物を使えるときの重さj以内での価値の最大値
    static int max_value[MAX_N][MAX_W] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= W; j++) {
            if (i > 0) {
                if (j >= w[i]) {
                    // i番目の品物を使うか使わないか、どちらか価値が大きい方が価値の最大値になる
                    max_value[i][j] = max(max_value[i-1][j], max_value[i-1][j-w[i]] + v[i]);
                } else {
                    // 重さの制約でi番目の品物を使えない場合は、i-1番目までの品物を使えるときの重さj以内での価値の最大値と等しくなる
                    max_value[i][j] = max_value[i-1][j];
                }
            } else {
                if (j >= w[i]) max_value[i][j] = v[i];
            }
        }
    }

    cout << max_value[n - 1][W] << endl;

    return 0;
}