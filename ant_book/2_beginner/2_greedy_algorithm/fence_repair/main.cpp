#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

#define MAX_N 20000

int main(){
    int n;
    list<int> l;
    int length = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        l.push_back(a);
        length += a;
    }

    int ans = 0;
    l.sort();
    while (l.front() < length) {
        int min1 = l.front();
        l.pop_front();
        int min2 = l.front();
        l.pop_front();

        ans += min1 + min2;

        if (l.back() < min1 + min2) {
            l.push_back(min1 + min2);
        } else {
            for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
                if (*it >= min1 + min2) {
                    l.insert(it, min1 + min2);
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}