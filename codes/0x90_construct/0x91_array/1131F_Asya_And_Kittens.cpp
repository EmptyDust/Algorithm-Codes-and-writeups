#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> nxt[n + 1];
    dsu d(n + 1);
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        nxt[d.get_root(v)].push_back(d.get_root(u));
        d.merge(u, v);
    }
    int p = d.get_root(1);
    std::function<void(int)> dfs = [&](int x) {
        std::cout << x << ' ';
        for (int nt : nxt[x]) {
            dfs(nt);
        }
        };
    dfs(p);
    return 0;
}