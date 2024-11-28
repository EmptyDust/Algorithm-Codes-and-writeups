#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    int m = 1 << n + 1;
    std::vector<i64> a(m), depth(m), dep(m), vis(m), cnt(n);
    for (int i = 2;i < m;++i)std::cin >> a[i];
    auto cal = [&](auto&& self, int u, i64 d, int dp) ->void {
        depth[u] = d;
        dep[u] = dp;
        if ((u << 1) >= m)return;
        self(self, u << 1, d + a[u << 1], dp + 1);
        self(self, u << 1 | 1, d + a[u << 1 | 1], dp + 1);
        };
    cal(cal, 1, 0, 0);
    auto lcdep = [&](int u, int v) {
        while (u != v) {
            u /= 2;
            v /= 2;
        }
        return dep[u];
        };
    std::vector<a3> p;
    for (int i = 1 << n;i < m;++i) {
        for (int j = i + 1;j < m;++j) {
            if (depth[i] == depth[j]) {
                p.push_back(a3{ lcdep(i,j), i, j });
            }
        }
    }
    ranges::sort(p, std::greater<>());
    int T = p.size();
    // std::cout << T << '\n';
    // for (auto [d, x, y] : p)std::cout << d << " " << x << " " << y << '\n';
    auto check = [&](int u, int v) {
        while (u != v) {
            if (vis[u] || vis[v])return true;
            u /= 2;
            v /= 2;
        }
        return false;
        };
    auto lca = [&](int u, int v) {
        while (u != v) {
            u /= 2;
            v /= 2;
        }
        return u;
        };
    int ans = 1e9;
    auto dfs = [&](auto&& self, int t, int c) {
        if (ans <= c)return;
        while (t < T) {
            auto [d, u, v] = p[t];
            if (!check(u, v))break;
            t++;
        }
        // std::cout << t << ' ' << c << "\n";
        if (t == T) {
            ans = c;
            return;
        }
        auto [d, u, v] = p[t];

        cnt[d]++;
        for (int i = n - 1, sum = 0;i >= 0;--i) {
            sum += cnt[i];
            if (sum > n - i) {
                cnt[d]--;
                return;
            }
        }

        int l = lca(u, v);
        assert(d == dep[l]);
        vis[l << 1] = 1;
        self(self, t, c + 1);
        vis[l << 1] = 0;
        vis[l << 1 | 1] = 1;
        self(self, t, c + 1);
        vis[l << 1 | 1] = 0;

        cnt[d]--;
        };
    dfs(dfs, 0, 0);
    if (ans == 1e9)ans = -1;
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}