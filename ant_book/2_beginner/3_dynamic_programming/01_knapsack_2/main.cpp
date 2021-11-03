#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_W 1000000001
#define MAX_V 10001
#define INF 1000000000

int main(){
    int n;
    int w[MAX_N], v[MAX_N];
    int W;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    // i番目までの品物を使えるときの価値jを構成する重さの最小値
    static long long int min_weight[MAX_V][MAX_N] = { INF };
    int ans = 0;
    for (int i = 1; i < MAX_V; i++) {
        for (int j = 0; j < n; j++) {
            cout << "i: " << i << endl;
            cout << "j: " << j << endl;
            cout << "min_weight[i][j]: " << min_weight[i][j] << endl;
            // if (j = 0) {
            //     if (i == v[j]) {
            //         min_weight[i][j] = w[j];
            //     }
            // } else if(i >= v[j]) {
            //     min_weight[i][j] = min(min_weight[i][j - 1], min_weight[i - v[j]][j - 1] + w[j]);
            // }
        }
    }

    for (int i = 1; i < MAX_V; i++) {
        if (min_weight[n - 1][i] <= W) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}