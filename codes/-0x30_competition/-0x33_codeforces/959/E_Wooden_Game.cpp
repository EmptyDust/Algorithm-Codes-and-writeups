#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int k;std::cin >> k;
    std::vector<int> sizes;
    for (int i = 0;i < k;++i) {
        int n;std::cin >> n;
        sizes.push_back(n);
        for (int j = 1;j < n;++j) {
            int p;std::cin >> p;
        }
    }
    std::vector<int> cnt(30);
    for (int x : sizes) {
        for (int i = 29;i >= 0;--i) {
            if (x >> i & 1)cnt[i]++;
        }
    }
    int ans = 0;
    for (int i = 29;i >= 0;--i) {
        // std::cout << cnt[i] << ' ';
        if (cnt[i] >= 2) {
            ans |= (1 << (i + 1)) - 1;
        }
        else if (cnt[i] == 1)
            ans |= 1 << i;
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