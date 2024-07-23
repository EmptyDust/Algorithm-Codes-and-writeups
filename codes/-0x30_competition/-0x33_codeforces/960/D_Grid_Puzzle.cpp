#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    int ans = 0;
    bool f = false;
    int cnt = 0;
    for (int i = 0;i < n;++i) {
        if (a[i] == 0) {
            f = 0;
        }
        else if (a[i] == 1 || a[i] == 2) {
            if (f) {
                if (cnt % 2) {
                    f = 0;
                }
                else ans++;
                cnt = 0;
            }
            else {
                f = 1;
                ans++;
            }
        }
        else if (a[i] == 3 || a[i] == 4) {
            ans++;
        }
        else {
            ans++;
            f = 0;
        }
        if (f)cnt++;
        else cnt = 0;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}