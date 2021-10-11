#include <iostream>
#include <algorithm>
#include <string>

#define MAX_A 1000000

using namespace std;


int main() {
    int n;
    static int a[MAX_A];

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = 0;

    for (int i = 0; i < n-2; i++) {
        if (a[n-i-1] < a[n-i-2] + a[n-i-3]) {
            ans = a[n-i-1] + a[n-i-2] + a[n-i-3];
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
