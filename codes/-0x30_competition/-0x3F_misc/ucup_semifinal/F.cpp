#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x, x |= 1 << 22;
    std::vector<int> p(23 + 1);
    auto insert = [&](int x) {
        int m = 0;
        for (int s = 22;s >= 0;--s)if (x >> s & 1) {
            if (!p[s]) {
                p[s] = x;
                return -1;
            }
            x ^= p[s];
            m |= 1 << s;
        }
        return m;
        };
    std::vector<int> dis((1 << 23), inf);
    for (auto& x : a) {
        auto y = insert(x);
        if (y != -1) {
            dis[y] = 1;
        }
    }
    for (int i = 0;i < 23;++i) dis[1 << i] = 1;
    int ans = inf;
    // for (int j = 1;j < (1 << 23);++j) {
    //     for (int sub = (j - 1) & j; sub > 0; sub -= j & (sub - 1)) {
    //         if (dis[j] == 1) ans = std::min(ans, dis[sub] + dis[j ^ sub] + 1);
    //         else dis[j] = std::min(dis[j], dis[sub] + dis[j ^ sub]);
    //     }
    // }
    for (int i = 0;i < 23;++i) {
        for (int j = 1;j < (1 << 23);++j) {
            if (j >> i & 1) {
                if (dis[j] == 1) ans = std::min(ans, dis[j ^ (1 << i)] + dis[1 << i] + 1);
                else dis[j] = std::min(dis[j], dis[j ^ (1 << i)] + dis[1 << i]);
            }
        }
    }
    if (ans == inf) {
        std::cout << "No";
    }
    else {
        std::cout << "Yes\n";
        std::cout << ans;
    }
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