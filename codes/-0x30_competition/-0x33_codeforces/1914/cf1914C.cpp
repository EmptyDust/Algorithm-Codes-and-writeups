#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 1e9 + 7;
using pt = pair<int, int>;
int a[MAXN], b[MAXN], dp[MAXN];

void solve() {
    int n, k;cin >> n >> k;
    for (int i = 0;i < n;++i)cin >> a[i];
    for (int i = 0;i < n;++i)cin >> b[i];
    int bcut = 0, acut = 0, ans = 0;
    for (int i = 0;i < n && i < k;++i) {
        acut += a[i];
        bcut = max(bcut, b[i]);
        ans = max(ans, acut + (k - i - 1) * bcut);
    }
    cout << ans;
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