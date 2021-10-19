#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 100

int main(){
    map<int, int> coin;
    int A;
    cin >> coin[1] >> coin[5] >> coin[10] >> coin[50] >> coin[100] >> coin[500];
    cin >> A;

    int money[6] = {500, 100, 50, 10, 5, 1};
    int ans = 0;

    for (int i = 0; i < 6; i++) {
        int n = min(A / money[i], coin[money[i]]);
        ans += n;
        A -= n * money[i];
    }

    cout << ans << endl;

    return 0;
}