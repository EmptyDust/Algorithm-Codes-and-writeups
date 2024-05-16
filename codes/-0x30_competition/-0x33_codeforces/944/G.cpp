#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], ans[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::map<int, std::vector<int>> num, pos;
    for (int i = 0;i < n;++i) {
        int x = nums[i];
        if (x & 1)x--;
        if (x >> 1 & 1)x -= 2;
        num[x].push_back(nums[i]);
        pos[x].push_back(i);
    }
    for (auto& [x, vt] : num) {
        std::sort(vt.begin(), vt.end());
        auto& ps = pos[x];
        for (int i = 0;i < vt.size();++i) {
            ans[ps[i]] = vt[i];
        }
    }
    for (int i = 0;i < n;++i)std::cout << ans[i] << ' ';
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