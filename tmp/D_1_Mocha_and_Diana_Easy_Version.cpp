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
    bool equal(int u, int v) {
        return get_root(u) == get_root(v);
    }
};

void solve() {
    int n, m1, m2;std::cin >> n >> m1 >> m2;
    dsu d1(n), d2(n);
    for (int i = 0;i < m1;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        d1.merge(u, v);
    }
    for (int i = 0;i < m2;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        d2.merge(u, v);
    }
    std::vector<pii> ans;
    for (int i = 0;i < n;++i) {
        for (int j = i + 1;j < n;++j) {
            if (!d1.equal(i, j) && !d2.equal(i, j)) {
                ans.push_back({ i + 1,j + 1 });
                d1.merge(i, j);
                d2.merge(i, j);
            }
        }
    }
    std::cout << ans.size() << '\n';
    for (auto [u, v] : ans)std::cout << u << ' ' << v << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}