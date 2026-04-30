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
    int n;std::cin >> n;
    std::vector<int> g[n];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::string s;std::cin >> s;
    int cnt1 = 0, cnt0 = 0, cntq = 0, cnto = 0;
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : g[u])if (v != p) {
            dfs(v, u);
        }
        if (u && s[u] == '?' && g[u].size() > 1) {
            cnto++;
        }
        if (u && g[u].size() == 1) {
            if (s[u] == '?')cntq++;
            if (s[u] == '0')cnt0++;
            if (s[u] == '1')cnt1++;
        }
        };
    dfs(0, -1);
    // std::cout << cntq << ' ' << cnto << '\n';
    if (s[0] != '?') {
        if (s[0] == '0') {
            int ans = cnt1 + (cntq + 1) / 2;
            std::cout << ans;
        }
        else {
            int ans = cnt0 + (cntq + 1) / 2;
            std::cout << ans;
        }
    }
    else {
        if (cnt1 > cnt0) {
            int ans = cnt1 + cntq / 2;
            std::cout << ans;
        }
        else if (cnt0 > cnt1) {
            int ans = cnt0 + cntq / 2;
            std::cout << ans;
        }
        else {
            int ans = cnt0 + cntq / 2;
            if (cnto % 2 && cntq % 2)ans++;
            std::cout << ans;
        }
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