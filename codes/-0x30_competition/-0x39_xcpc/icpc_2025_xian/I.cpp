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

struct DSU {
    std::vector<int> d;
    DSU(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
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
    std::vector dis(n + 1, std::vector<int>(n + 1));
    std::vector<int> f(n + 1, 1);
    for (int i = 1;i <= n;++i) {
        for (int j = i;j <= n;++j) {
            std::cin >> dis[i][j];
            if (i != j && dis[i][j] == i) f[i] = 0;
            if (i != j && dis[i][j] == j) f[j] = 0;
            dis[i][j] ^= i;
            dis[i][j] ^= j;
            dis[j][i] = dis[i][j];
        }
    }
    // for (int i = 1;i <= n;++i) {
    //     for (int j = 1;j <= n;++j) {
    //         std::cout << dis[i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }
    DSU dsu(n + 1);
    std::vector<int> trust(n + 1);
    int cnt = 0;
    for (int i = 1;i <= n;++i) {
        for (int j = i + 1;j <= n;++j) {
            if (dis[i][j] == 0 && (f[i] || f[j])) {
                std::cout << i << ' ' << j << '\n';
                dsu.merge(i, j);
                trust[i] = j;
                trust[j] = i;
                cnt++;
            }
        }
    }
    std::vector g(n + 1, std::set<int>());
    std::vector<int> d(n + 1);
    for (int i = 1;i <= n;++i) {
        for (int j = i + 1;j <= n;++j) {
            if (!f[i] && !f[j] && dis[i][j] == 0 && dis[trust[i]][j] == i && dis[i][trust[j]] == j && dsu.get_root(i) != dsu.get_root(j)) {
                g[i].insert(j);
                g[j].insert(i);
                d[i]++;
                d[j]++;
            }
        }
    }
    std::vector<int> leaves;
    for (int i = 1;i <= n;++i) {
        // std::cout << f[i] << ' ';
        if (d[i] == 1) leaves.push_back(i);
    }
    for (int i = 0;i < leaves.size();++i) {
        int u = leaves[i];
        if (d[u] == 0) continue;
        int v = *g[u].begin();
        std::cout << u << ' ' << v << '\n';
        g[v].erase(u);
        cnt++;
        for (int x : g[v]) {
            d[x]--;
            g[x].erase(v);
            if (d[x] == 1) {
                leaves.push_back(x);
            }
        }
    }
    assert(cnt <= n - 1);
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