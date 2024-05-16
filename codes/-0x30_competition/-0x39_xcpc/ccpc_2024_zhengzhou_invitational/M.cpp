#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
#define int long long
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    auto check = [&](int x) {
        int u = a[0] + b[0] * x, d = a[0] - b[0] * x;
        for (int i = 0;i < n;++i) {
            int uc = a[i] + b[i] * x, dc = a[i] - b[i] * x;
            u = std::min(u, uc);
            d = std::max(d, dc);
        }
        return u >= d;
        };
    int ans = inf;
    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = std::min(ans, mid);
        }
        else l = mid + 1;
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