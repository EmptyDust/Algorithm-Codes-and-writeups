#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 1e9 + 7;
using pt = pair<int, int>;

void solve() {
    int n, k;cin >> n >> k;
    for (int i = n - k;i <= n;++i)cout << i << ' ';
    for (int i = n - k - 1;i >= 1;--i)cout << i << ' ';
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