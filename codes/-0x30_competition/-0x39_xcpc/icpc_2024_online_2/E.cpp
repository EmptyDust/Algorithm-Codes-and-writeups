#include<bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;
const int inf = 1e9 + 100;
using a3 = std::array<int, 3>;
using a5 = std::array<int, 5>;

void solve() {
    int n, m, d;std::cin >> n >> m >> d;
    std::vector adj(n, std::vector<int>());
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int num;std::cin >> num;
    std::vector<int> s(num);
    std::vector vis(n, std::vector<int>(2, -1));
    std::queue<a3> q;
    for (int& x : s)std::cin >> x, x--, q.push({ x,0,0 });
    while (q.size()) {
        auto [u, t, c] = q.front();
        q.pop();
        if (c > d || vis[u][t] != -1)continue;
        vis[u][t] = c;
        for (auto v : adj[u]) {
            q.push({ v, !t, c + 1 });
        }
    }
    std::queue<a5> check;
    std::vector ans(n, std::vector<pii>(2));
    check.push({ 0,0,0,-1,-1 });
    while (check.size()) {
        auto [u, t, c, pu, pt] = check.front();
        check.pop();
        if (vis[u][t] != -1 && vis[u][t] <= c)continue;
        vis[u][t] = 0;
        ans[u][t] = { pu,pt };
        if (u == n - 1) {
            std::vector<int> out;
            while (u != -1) {
                out.push_back(u + 1);
                auto [nu, nt] = ans[u][t];
                u = nu, t = nt;
            }
            std::cout << (int)out.size() - 1 << '\n';
            std::reverse(out.begin(), out.end());
            for (int i = 0;i < out.size();++i)
                std::cout << out[i] << " \n"[i + 1 == out.size()];
            return;
        }
        for (auto v : adj[u]) {
            check.push(a5{ v,!t,c + 1,u,t });
        }
    }
    std::cout << -1 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
3
7 8 99
1 2
1 3
3 7
4 5
5 6
6 3
1 5
2 4
2 2 6
7 8 99
1 2
1 3
3 7
4 5
5 6
6 3
1 5
2 4
2 2 3
7 9 1
1 2
1 3
3 7
4 5
5 6
6 3
1 5
2 4
1 4
1 7
*/
/*
1
7 9 1
1 4
1 2
1 3
1 5
2 4
3 6
3 7
4 5
5 6
1 7
*/