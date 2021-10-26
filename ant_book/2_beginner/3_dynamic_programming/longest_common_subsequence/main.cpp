#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1001
#define MAX_M 1001

int main(){
    int n, m;
    string s, t;

    cin >> n >> m;
    cin >> s >> t;

    static int lcs[MAX_N][MAX_M] = { 0 };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                lcs[i][j] = max(lcs[i-1][j-1] + 1, max(lcs[i][j-1], lcs[i-1][j]));
            } else {
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }

    cout << lcs[n][m] << endl;

    return 0;
}