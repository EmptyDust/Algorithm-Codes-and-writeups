#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n + 1), p(n + 1), vis(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int i = 1;i <= n;++i)p[a[i]] = i;
    std::vector<int> cnt;
    for (int i = 1;i <= n;++i)if (!vis[i] && a[i] != i) {
        vis[i] = 1;
        int x = a[i];
        int c = 1;
        while (x != i) {
            c++;
            vis[x] = 1;
            x = a[x];
        }
        cnt.push_back(c);
    }
    int c = 0;
    for (int& x : cnt) {
        if (x == 2) {
            c++;
            x = 0;
        }
    }
    int ans = c / 2;bool f = c % 2;
    for (int x : cnt) {
        if (x == 0)continue;
        else {
            if (x & 1)ans += (x - 3) / 2 + 1;
            else ans += (x - 4) / 2 + 1;
        }
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