#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> b(n);
    for (int& x : b)std::cin >> x, x += 100;
    std::vector<int> pos[101];
    pos[0].push_back(0);
    for (int i = 0;i < n;++i) {
        if (b[i] > 0)
            pos[b[i]].push_back(i + 1);
    }
    int q;std::cin >> q;
    while (q--) {
        int l, r;std::cin >> l >> r;
        int cnt = 0;
        for (int i = 0;i <= 100;++i) {
            auto lb = std::lower_bound(pos[i].begin(), pos[i].end(), l);
            if (lb == pos[i].end())continue;
            if (lb - pos[i].begin() <= r)cnt++;
        }
        std::cout << cnt << '\n';
    }
    return 0;
}