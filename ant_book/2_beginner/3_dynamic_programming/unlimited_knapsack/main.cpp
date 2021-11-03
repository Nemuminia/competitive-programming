#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_W 1000000000

int main(){
    int n;
    int w[MAX_N], v[MAX_N];
    int W;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    int dp[MAX_W+1] = { 0 };

    for (int i = 1; i <= W; i++) {
        for(int j = 0; j < n; j++) {
            if(i - w[j] >= 0) {
                dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
            }
        }
    }

    cout << dp[W] << endl;

    return 0;
}