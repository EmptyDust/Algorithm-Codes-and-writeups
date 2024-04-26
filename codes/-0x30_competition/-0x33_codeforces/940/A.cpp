#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::map<int, int> cnt;
    for (int i = 0;i < n;++i)std::cin >> nums[i], cnt[nums[i]]++;
    i64 ans = 0;
    for (auto [num, ct] : cnt) {
        ans += ct / 3;
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