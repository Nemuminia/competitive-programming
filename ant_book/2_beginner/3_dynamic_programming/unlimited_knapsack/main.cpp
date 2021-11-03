#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_W 10001

int main(){
    int n;
    int w[MAX_N], v[MAX_N];
    int W;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    int max_value[MAX_W] = { 0 };

    for (int i = 1; i < W; i++) {
        for(int j = 0; j < n; j++) {
            if(i - w[j] >= 0) {
                max_value[i] = max(max_value[i], max_value[i - w[j]] + v[j]);
            }
        }
    }

    cout << max_value[W] << endl;

    return 0;
}