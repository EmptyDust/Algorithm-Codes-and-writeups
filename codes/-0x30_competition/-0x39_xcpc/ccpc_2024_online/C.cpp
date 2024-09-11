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
    int n, m;std::cin >> n >> m;
    std::vector<int> a(n);
    int r = 0;
    for (int i = 0;i < m;++i) {
        int x;std::cin >> x;
        x--;
        a[x]++;
        r = x;
    }
    std::vector<int> g[n];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    std::function<int(int, int)> dfs = [&](int u, int p)->int {
        int c = 1;
        for (int& v : g[u])if (v != p) {
            c += dfs(v, u);
        }
        if (a[u]) {
            ans += c / 2;
            if (p != -1 && c > 1 && c % 2 == 0)a[p] = 1;
            return 0;
        }
        return c;
        };  
    dfs(r, -1);
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