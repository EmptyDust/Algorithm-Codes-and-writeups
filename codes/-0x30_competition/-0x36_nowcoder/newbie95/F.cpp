#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    std::vector<pt> pts(n);
    for (auto& [v, w] : pts)std::cin >> v >> w;
    std::vector<bool> use(n, true);
    int ans = 0;
    for (int s = 29;s >= 0;s--) {
        int curv = (1 << 30) - 1;
        for (int i = 0;i < n;++i)if (use[i]) {
            auto& [v, w] = pts[i];
            if (w >> s & 1)
                curv &= v;
        }
        if (curv <= k) {
            ans |= 1 << s;
            for (int i = 0;i < n;++i)if (use[i] && (pts[i].second >> s & 1) == 0)
                use[i] = false;
        }
    }
    std::cout << ans;
    return 0;
}