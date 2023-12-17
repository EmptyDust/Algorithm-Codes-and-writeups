#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b;cin >> a >> b;
    cout << max(a, b);
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