#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 2000

int main(){
    int n;
    char s[MAX_N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }


    int front = 0;
    int back = n - 1; 
    queue<char> t;

    while (front <= back) {
        bool getFront = true;
        for(int i = 0; front + i <= back - i ; i++) {
            if (s[front + i] < s[back - i]) {
                getFront = true;
                break;
            } else if (s[front + i] > s[back - i]) {
                getFront = false;
                break;
            }
        }

        if (getFront) {
            t.push(s[front++]);
        } else {
            t.push(s[back--]);
        }
    }


    while (!t.empty()) {
        cout << t.front();
        t.pop();
    }
    cout << endl;

    return 0;
}