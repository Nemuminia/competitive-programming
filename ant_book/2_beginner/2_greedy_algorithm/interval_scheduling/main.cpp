#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int main(){
    int n;
    int s[MAX_N], t[MAX_N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    pair<int, int> work_time[MAX_N];
    for (int i = 0; i < n; i++) {
        // ソートキーであるtをpairのfirst要素に設定する
        work_time[i] = pair<int, int>(t[i], s[i]);
    }    
    sort(work_time, work_time + n);

    int ans = 0;
    int end_time = -1;

    for (int i = 0; i < n; i++) {
        if (end_time < work_time[i].second) {
            end_time = work_time[i].first;
            ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}