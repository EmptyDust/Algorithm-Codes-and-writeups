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
    int n, k;std::cin >> n >> k;
    std::vector<int> g[n + 1];
    for (int i = 0;i < n - 1;++i) {
        int u, v;std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> cnt(n + 1);
    for (int i = 0;i < k;++i) {
        int x;std::cin >> x;
        cnt[x]++;
    }
    int ans = 1;
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : g[u])if (v != p) {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
        if (cnt[u] && cnt[u] < k)ans++;
        };
    dfs(1, 0);
    std::cout << ans;
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