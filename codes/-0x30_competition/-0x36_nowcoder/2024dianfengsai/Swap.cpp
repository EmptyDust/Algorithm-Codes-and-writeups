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

void solve() {
    int n, m, q;std::cin >> n >> m >> q;
    std::vector
        value_on_pos(n + 1, std::vector<pii>()),
        pos_of_value(n + 1, std::vector<pii>());
    std::vector<int> a(n + 1);std::iota(a.begin(), a.end(), 0);
    std::vector<pii> info(m + 1);
    for (int i = 1;i <= n;++i){
        pos_of_value[i].push_back({ 0,i });
        value_on_pos[i].push_back({ 0,i });
    }
    for (int i = 1;i <= m;++i){
        auto& [u, v] = info[i];
        std::cin >> u >> v;
        pos_of_value[a[u]].push_back({ i,v });
        pos_of_value[a[v]].push_back({ i,u });
        value_on_pos[u].push_back({ i,a[v] });
        value_on_pos[v].push_back({ i,a[u] });
        std::swap(a[u], a[v]);
    }
    for (int i = 0;i < q;++i){
        int l, r, k;std::cin >> l >> r >> k;
        auto it1 = --std::lower_bound(value_on_pos[k].begin(), value_on_pos[k].end(), pii{ r,inf });
        auto x = (*it1).second;
        auto it2 = --std::lower_bound(pos_of_value[x].begin(), pos_of_value[x].end(), pii{ l - 1,inf });
        auto p = (*it2).second;
        std::cout << p << '\n';
    }
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