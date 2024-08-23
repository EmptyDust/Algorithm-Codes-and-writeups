#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct dsu {
    std::vector<int> d;
    int cnt;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0);cnt = n; }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            cnt--;
            return true;
        }
        else return false;
    }
    int cal() {
        return cnt;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;std::cin >> n >> q;
    std::vector<dsu> ds(11, dsu(n));
    for (int i = 0;i < n - 1;++i) {
        int u, v, w;std::cin >> u >> v >> w;u--, v--;
        for (int j = w;j <= 10;++j) {
            ds[j].merge(u, v);
        }
    }
    while (q--) {
        int u, v, w;std::cin >> u >> v >> w;u--, v--;
        for (int j = w;j <= 10;++j) {
            ds[j].merge(u, v);
        }
        int cur = n;
        int res = 0;
        for (int j = 1;j <= 10;++j) {
            int c = cur - ds[j].cal();
            res += c * j;
            cur = ds[j].cal();
        }
        std::cout << res << '\n';
    }
    return 0;
}