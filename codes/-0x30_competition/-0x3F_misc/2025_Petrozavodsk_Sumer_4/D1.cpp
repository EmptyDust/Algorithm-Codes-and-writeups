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

struct dsu {
    std::vector<int> d;
    int cnt;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); cnt = n; }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            cnt--;
            return true;
        }
        else return false;
    }
};

void solve() {
    int n, m, q;std::cin >> n >> m >> q;
    std::set<a2> edges;
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        if (u > v)std::swap(u, v);
        edges.insert({ u, v });
    }
    std::vector<a2> del;
    for (i64 i = 0, a = 0, b = 0;i < q;++i) {
        int x, y;std::cin >> x >> y;
        x = (a + x) % n;
        y = (b + y) % n;
        a = (a * 2 + 1) % n;
        b = (b * 3 + 1) % n;
        // std::cout << a << ' ' << b << ' ' << x << ' ' << y << '\n';
        if (x > y)std::swap(x, y);
        if (edges.count({ x, y })) {
            del.push_back({ x, y });
            edges.erase({ x, y });
        }
        else del.push_back({ -1, -1 });
    }
    dsu d(n);
    for (auto [u, v] : edges) {
        d.merge(u, v);
    }
    for (int i = q - 1;i >= 0;--i) {
        if (d.cnt == 1) {
            for (int j = 0;j <= i;++j) {
                std::cout << 1 << '\n';
            }
            for (int j = i + 1;j < q;++j) {
                std::cout << 0 << '\n';
            }
            return;
        }
        auto [u, v] = del[i];
        if (u == v)
            continue;
        d.merge(u, v);
    }
    for (int j = 0;j < q;++j) {
        std::cout << 0 << '\n';
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