#include <iostream>
#include <algorithm>

#define MAX_N 20

using namespace std;

int n, a[MAX_N], k;

bool dfs(int i, int sum) {
    if (i == n) {
        return sum == k;
    }
    
    // 集合の中からいくつか選び～的な問題は、各要素ごとに"選ぶ"or"選ばない"の2パターンがある
    // 選ぶパターン, 選ばないパターンを再帰関数で全探索する
    return (dfs(i + 1, sum) || dfs(i + 1, sum + a[i]));
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;

    bool ans = dfs(0, 0);

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}