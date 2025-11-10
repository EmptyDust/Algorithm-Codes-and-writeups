#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n), vis(n);
    for (auto& x : a)std::cin >> x;
    std::vector g(n, std::vector<int>());
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::set<a2> st;
    for (int i = 0;i < n;++i) {
        st.insert(a2{ a[i], i });
    }
    i64 ans = 0;
    while (st.size()) {
        auto [x, u] = *st.begin();
        st.erase(st.begin());
        vis[u] = 1;
        ans += x;
        for (auto v : g[u]) if (!vis[v]) {
            st.erase({ a[v], v });
            a[v] += x;
            st.insert({ a[v], v });
        }
    }
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