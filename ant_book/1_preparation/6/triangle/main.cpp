#include <iostream>
#include <algorithm>
#include <string>

#define MAX_ 1000000

using namespace std;


int main() {
    int n;
    static int a[MAX_N];

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;

    sort(a, a + n);

    for (int i = 0; i < n-2; i++) {
        if (a[n-i-1] < a[n-i-2] + a[n-i-3]) {
            ans = a[n-i-1] + a[n-i-2] + a[n-i-3];
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
