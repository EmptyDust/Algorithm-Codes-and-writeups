#include <bits/stdc++.h>
#define int long long 
using namespace std;
char mp[3][3];

void solve() {
    int k;
    for (int i = 0;i < 3;++i) {
        for (int j = 0;j < 3;++j) {
            cin >> mp[i][j];
            if (mp[i][j] == '?')k = i;
        }
    }
    bool A, B, C;
    A = B = C = false;
    for (int i = 0;i < 3;++i) {
        if (mp[k][i] == 'A')A = true;
        if (mp[k][i] == 'B')B = true;
        if (mp[k][i] == 'C')C = true;
    }
    if (!A)cout << 'A';
    if (!B)cout << 'B';
    if (!C)cout << 'C';
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}