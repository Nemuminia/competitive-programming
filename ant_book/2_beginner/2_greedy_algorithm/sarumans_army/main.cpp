#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000

int main(){
    int n, r;
    int x[MAX_N];
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    int ans = 0;
    int uncovered = 0;
    for (int i = 0; i < n; i++) {
        if (x[uncovered] + r < x[i]) {
            ans++;
            uncovered = i;
        }
    }

    cout << ans << endl;

    return 0;
}