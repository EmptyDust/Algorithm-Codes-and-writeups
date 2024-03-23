#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9;
using pt = std::pair<int, int>;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int u, v, color;
    std::map<int, std::set<int>> mp;
    std::vector<std::set<int>> colors(n);
    while (m--) {
        std::cin >> u >> v >> color;
        u--, v--;
        mp[color].insert(u);
        mp[color].insert(v);
        colors[u].insert(color);
        colors[v].insert(color);
    }
    int b, e;
    std::cin >> b >> e;
    b--, e--;
    std::vector<int> f(n, inf);
    std::queue<int> q;
    std::set<int> st;
    q.push(b);
    f[b] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == e) {
            std::cout << f[cur];
            return;
        }
        for (int color : colors[cur])if (!st.count(color)) {
            st.insert(color);
            for (int x : mp[color])if (f[cur] + 1 < f[x]) {
                f[x] = f[cur] + 1;
                q.push(x);
            }
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