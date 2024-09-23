#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n + 1), c(n + 1);
    for (int i = 0;i < n;++i) {
        int x, y;std::cin >> x >> y;
        if (x > y) {
            std::swap(x, y);
            c[x] = 1;
        }
        if (x <= n) {
            a[x] = y;
        }
        else {
            std::cout << -1;
            return;
        }
    }
    std::vector<int> suf(n + 2);
    for (int i = n;i >= 1;--i) {
        suf[i] = std::max(suf[i + 1], a[i]);
    }
    int pre = inf;
    int cost0 = 0, cost1 = 0, ans = 0;
    std::vector<int> sq0, sq1;
    for (int i = 1;i <= n;++i) {
        pre = std::min(pre, a[i]);
        if (sq0.empty() || a[sq0.back()] > a[i]) {
            sq0.push_back(i);
            cost0 += c[i];
        }
        else if (sq1.empty() || a[sq1.back()] > a[i]) {
            sq1.push_back(i);
            cost1 += c[i];
        }
        else {
            std::cout << -1;
            return;
        }
        if (pre > suf[i + 1]) {
            int s0 = sq0.size(), s1 = sq1.size();
            ans += std::min(cost0 + s1 - cost1, cost1 + s0 - cost0);
            cost0 = cost1 = 0;
            sq0.clear();
            sq1.clear();
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}