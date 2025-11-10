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
    int n, m;std::cin >> n >> m;
    std::vector<a3> info(m);
    for (auto& [c, a, b] : info)std::cin >> a >> b >> c, a--, b--;
    ranges::sort(info, std::greater<a3>());
    dsu d(n);
    std::vector<int> e(n, -1);
    for (auto [c, a, b] : info) {
        if (e[a] != -1 && e[b] != -1) {
            if (d.get_root(e[a]) == d.get_root(e[b])) {
                std::cout << c;
                return;
            }
        }
        if (e[a] == -1) {
            e[a] = b;
        }
        else d.merge(e[a], b);
        if (e[b] == -1) {
            e[b] = a;
        }
        else d.merge(e[b], a);
        // std::cout << a << " " << b << '\n';
    }
    std::cout << 0;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}