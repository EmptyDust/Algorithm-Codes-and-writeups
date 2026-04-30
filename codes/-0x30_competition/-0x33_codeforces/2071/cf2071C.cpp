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
    int n, st, en;
    std::cin >> n >> st >> en;st--, en--;
    if (n == 1) {
        std::cout << 1;
        return;
    }
    std::vector adj(n, std::vector<int>());
    std::vector<int> cnt(n), ans;
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
    std::vector<int> leaves;
    for (int i = 0;i < n;++i)if (cnt[i] == 1 && i != en) {
        leaves.push_back(i);
    }
    while (leaves.size()) {
        int u = leaves.back();
        leaves.pop_back();
        ans.push_back(u);
        for (int v : adj[u]) {
            cnt[v]--;
            if (cnt[v] == 1 && v != en) {
                leaves.push_back(v);
            }
            if (cnt[v] == 0 && v == en) {
                leaves.push_back(v);
            }
        }
    }
    for (int x : ans)std::cout << x + 1 << " ";
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