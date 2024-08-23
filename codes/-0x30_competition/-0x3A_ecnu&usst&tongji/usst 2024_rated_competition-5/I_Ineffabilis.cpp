#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;

std::vector<pii> adj[MAXN];

i64 cur;
int pos;
void dfs(int x, int p, i64 d) {
    if (d > cur) {
        cur = d;
        pos = x;
    }
    for (auto [nxt, dis] : adj[x])if (nxt != p) {
        dfs(nxt, x, d + dis);
    }
}

a3 get_diam() {
    cur = 0, pos = 1;
    dfs(pos, 0, cur);
    int u = pos;
    cur = 0;
    dfs(pos, 0, cur);
    int v = pos;
    return { u,v,cur };
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> color(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> color[i];
    for (int i = 1;i < n; ++i) {
        int a, b;std::cin >> a >> b;
        int c = color[a] != color[b];
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
        // std::cout << a << ' ' << b << ' ' << c << '\n';
    }

    auto [u, v, d] = get_diam();
    std::cout << (d + 1) / 2;
    return 0;
}