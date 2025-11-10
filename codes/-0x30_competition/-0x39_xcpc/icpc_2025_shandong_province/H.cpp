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
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<a4> edges(m);
    for (int i = 0;i < m;++i) {
        auto& [w, u, v, idx] = edges[i];
        std::cin >> u >> v >> w;
        idx = i + 1;
    }
    // assert(0);
    dsu d(n + 1);
    ranges::sort(edges);
    i64 ans = 0;
    std::vector<a2> ans1;
    std::vector<int> ans2;
    for (int i = 0, cnt = 0;cnt < n - 1 - k || i < m && edges[i][0] <= 1;++i) {
        auto [w, u, v, idx] = edges[i];
        if (d.merge(u, v)) {
            ans += w;
            cnt++;
            ans2.push_back(idx);
        }
    }
    for (int i = 2, idx = m + 1;i <= n;++i) {
        if (d.merge(i - 1, i)) {
            ans1.push_back({ i - 1, i });
            ans2.push_back(idx++);
            ans++;
        }
    }
    std::cout << ans1.size() << '\n';
    for (auto [u, v] : ans1)std::cout << u << ' ' << v << '\n';
    std::cout << ans << '\n';
    for (auto x : ans2)std::cout << x << " ";
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