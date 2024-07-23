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

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::map<int, std::vector<int>> map;
    dsu d(n);
    std::cout << "YES\n";
    std::vector<pii> ans;
    for (int j = n - 1;j > 0;--j) {
        for (int i = 0;i < n;++i) {
            int m = a[i] % j;
            map[m].push_back(i);
        }
        bool f = true;
        for (int i = 0;i < j && f;++i) if (map[i].size() > 1) {
            int sz = map[i].size();
            int u = map[i][0];
            for (int k = 1;k < sz;++k) {
                int v = map[i][k];
                if (d.merge(u, v)) {
                    ans.push_back({ u + 1,v + 1 });
                    f = false;
                    break;
                }
            }
        }
        map.clear();
    }
    std::reverse(ans.begin(), ans.end());
    for (auto [u, v] : ans) {
        std::cout << u << ' ' << v << '\n';
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