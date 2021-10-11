#include <iostream>
#include <algorithm>

#define MAX_N 1000000

using namespace std;

int main() {
    int L;
    int n;
    static int x[MAX_N];

    cin >> L >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int ans_min = 0;
    int ans_max = 0;

    for (int i = 0; i < n; i++) {
        ans_min = max(ans_min, min(x[i], L-x[i]));
        ans_max = max(ans_max, max(x[i], L-x[i]));
    }

    cout << "min = " << ans_min << endl;
    cout << "max = " << ans_max << endl;

    return 0;
}