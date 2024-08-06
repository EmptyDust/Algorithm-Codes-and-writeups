#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int ans = 0;
    auto check = [&](auto x)->bool {
        std::vector<int> vis(x + 1), cnt(x + 1);
        for (int i = 0;i < n;++i) {
            if (a[i] <= x) {
                if (vis[a[i]])cnt[a[i]]++;
                vis[a[i]] = 1;
            }
            else {
                int y = a[i];
                while (y > x) {
                    y /= 2;
                }
                cnt[y]++;
            }
        }
        for (int i = x;i >= 0;--i) {
            if (!vis[i])
                if (cnt[i] == 0)return false;
                else {
                    cnt[i]--;
                }
            cnt[i / 2] += cnt[i];
        }
        return true;
        };
    // std::cout << check(3) << " ";
    while (l <= r) {
        auto mid = l + r >> 1;
        if (check(mid))
            l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    std::cout << ans + 1;
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