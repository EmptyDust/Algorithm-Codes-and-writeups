#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    i64 n, k;std::cin >> n >> k;
    std::vector<i64> ans(n);
    int i = 0;
    while (k - ((i64)1 << i) >= 0) {
        ans[0] += (i64)1 << i;
        k -= (i64)1 << i;
        ++i;
    }
    ans[n - 1] += k;
    for (auto x : ans)std::cout << x << ' ';
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