#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 2e5 + 10;
std::vector<int> adj[MAXN];
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    int u, v;
    for (int i = 1;i < n;++i) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<pt> monsters(m);
    for (int i = 0;i < m;++i)std::cin >> monsters[i].first >> monsters[i].second;
    sort(monsters.begin(), monsters.end(), [&](pt a, pt b) {return a.second < b.second;});
    std::vector<int> f(n + 1, -1);
    std::queue<pt> q;
    int t = monsters[0].second;
    for (int i = 0;i < m;++i) {
        while (t < monsters[i].second) {
            std::queue<pt> tmp;
            while (!q.empty()) {
                pt cur = q.front();
                q.pop();
                for (int nxt : adj[cur.first])if (nxt != cur.second) {
                    if (~f[nxt]) {
                        std::cout << f[nxt] + f[cur.first] + 1;
                        return 0;
                    }
                    f[nxt] = f[cur.first] + 1;
                    tmp.push({ nxt,cur.first });
                }
            }
            q = tmp;
            t++;
        }
        if (~f[monsters[i].first]) {
            std::cout << monsters[i].second * 2;
            return 0;
        }
        f[monsters[i].first] = monsters[i].second;
        q.push({ monsters[i].first,-1 });
    }
    while (!q.empty()) {
        pt cur = q.front();
        q.pop();
        for (int nxt : adj[cur.first])if (nxt != cur.second) {
            if (~f[nxt]) {
                std::cout << f[nxt] + f[cur.first] + 1;
                return 0;
            }
            f[nxt] = f[cur.first] + 1;
            q.push({ nxt,cur.first });
        }
    }
    return 0;
}