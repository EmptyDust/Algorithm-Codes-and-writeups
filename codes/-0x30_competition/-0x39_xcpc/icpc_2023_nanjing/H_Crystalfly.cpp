#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
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
    std::vector<i64> a(n), t(n);
    for (auto& x : a)std::cin >> x;
    for (auto& x : t)std::cin >> x;
    std::vector adj(n, std::vector<int>());
    for (int i = 0;i < n - 1;++i){
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::function<pii(int, int)> dfs = [&](int u, int p){
        i64 max = 0;
        std::vector<a2> leafmax(2, { 0,-1 }), max3(2, { 0,-1 });
        pii ret = { 0,0 };
        for (auto v : adj[u])if (v != p){
            auto [r0, r1] = dfs(v, u);
            ret.first += r1;
            max = std::max(max, a[v]);
            a2 x = { a[v] - (r1 - r0),v };
            for (int i = 0;i < 2;++i){
                if (x[0] > leafmax[i][0]){
                    std::swap(x, leafmax[i]);
                }
            }
            if (t[v] == 3){
                a2 x = { a[v],v };
                for (int i = 0;i < 2;++i){
                    if (x[0] > max3[i][0]){
                        std::swap(x, max3[i]);
                    }
                }
            }
        }
        if (leafmax[0][1] != max3[0][1])max = std::max(max, leafmax[0][0] + max3[0][0]);
        else
            max = std::max(max, std::max(leafmax[0][0] + max3[1][0], leafmax[1][0] + max3[0][0]));
        ret.second = ret.first + max;
        return ret;
        };
    auto [_, ans] = dfs(0, -1);
    std::cout << ans + a[0];
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