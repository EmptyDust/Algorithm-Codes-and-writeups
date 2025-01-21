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
    int n, m, q;std::cin >> n >> m >> q;
    std::vector<a3> edges;
    for (int i = 0;i < m;++i) {
        i64 u, v, w;std::cin >> u >> v >> w;u--, v--;
        edges.push_back({ u,v,w });
    }
    ranges::sort(edges, [&](a3& x, a3& y) {return x[2] < y[2];});
    std::vector dis(n, std::vector<std::vector<int>>(n, std::vector<int>(n, inf)));
    for (int i = 0;i < n;++i)dis[0][i][i] = 0;
    for (auto& [u, v, w] : edges) dis[0][u][v] = dis[0][v][u] = 1;
    for (int x = 0;x < n;++x) {
        for (int y = 0;y < n;++y) {
            for (int z = 0;z < n;++z) {
                dis[0][y][z] = std::min(dis[0][y][z], dis[0][y][x] + dis[0][x][z]);
            }
        }
    }
    std::vector<int> value(n);
    int p = 1;
    dsu d(n);
    for (auto& [u, v, w] : edges) {
        if (d.merge(u, v)) {
            for (int i = 0;i < n;++i) {
                for (int j = 0;j < n;++j) {
                    dis[p][i][j] = std::min({ dis[p - 1][i][j], dis[p - 1][i][u] + dis[p - 1][v][j], dis[p - 1][i][v] + dis[p - 1][u][j] });
                }
            }
            value[p++] = w;
        }
    }
    while (q--) {
        int u, v, k;std::cin >> u >> v >> k;u--, v--;
        int low = 0, high = n - 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (dis[mid][v][u] < k) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        std::cout << value[high] << " ";
    }
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