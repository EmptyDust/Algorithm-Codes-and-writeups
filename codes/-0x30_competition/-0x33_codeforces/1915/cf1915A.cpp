#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int a, b, c;cin >> a >> b >> c;
    cout << (a ^ b ^ c);
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