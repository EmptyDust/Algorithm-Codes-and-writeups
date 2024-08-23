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

std::vector<int> g[MAXN];

int vis[MAXN];

i64 cnt, d;
void dfs(int x) {
    cnt++;
    vis[x] = 1;
    d += g[x].size();
    for (auto v : g[x]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n, m;std::cin >> n >> m;
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> cnts;
    i64 ans = 0;
    for (int i = 1;i <= n;++i) {
        if (!vis[i]) {
            cnt = 0;d = 0;
            dfs(i);
            cnts.push_back(cnt);
            ans += cnt * (cnt - 1) / 2 - d / 2;
        }
    }
    if (!ans) {
        ranges::sort(cnts);
        ans += 1ll * cnts[0] * cnts[1];;
    }
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