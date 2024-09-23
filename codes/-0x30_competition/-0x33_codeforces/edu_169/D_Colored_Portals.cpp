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

const std::string brgy = "BRGY";
void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n);

    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < 2;++j)
            for (int k = 0;k < 4;++k)
                if (s[j] == brgy[k]) {
                    a[i] |= 1 << k;
                    break;
                }
    }

    std::vector<std::vector<int>> g(n);
    std::vector<int> p(16, -1);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < 16;++j)
            if ((j & a[i]) && p[j] != -1)
                g[i].push_back(p[j]);
        p[a[i]] = i;
    }
    p.assign(16, -1);
    for (int i = n - 1;i >= 0;--i) {
        for (int j = 0;j < 16;++j)
            if ((j & a[i]) && p[j] != -1)
                g[i].push_back(p[j]);
        p[a[i]] = i;
    }

    int ans;
    std::function<void(int, int, int, int)> dfs = [&](int u, int depth, int cur, int y) {
        // std::cout << u << ' ';
        if (a[u] & a[y]) {
            ans = std::min(ans, cur + std::abs(u - y));
            return;
        }
        if (cur >= ans || depth >= 3)return;
        for (int v : g[u])
            dfs(v, depth + 1, cur + std::abs(u - v), y);
        };

    for (int i = 0;i < q;++i) {
        int x, y;std::cin >> x >> y;
        x--, y--;
        if (x == y) {
            std::cout << 0 << '\n';
            continue;
        }
        ans = inf;
        dfs(x, 0, 0, y);
        int tmp = ans;
        ans = inf;
        dfs(y, -0, 0, x);
        ans = std::min(ans, tmp);
        if (ans == inf)ans = -1;
        std::cout << ans << '\n';
    }
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