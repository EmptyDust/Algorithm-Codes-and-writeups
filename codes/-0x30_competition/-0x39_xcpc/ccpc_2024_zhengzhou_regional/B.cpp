#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector map(n, std::vector<int>()), id(n, std::vector<int>());
    std::vector adj(2 * n * n, std::vector<int>());
    for (int i = 0, idx = 0;i < n;++i) {
        for (int j = 0;j < 2 * i + 1;++j) {
            int x;std::cin >> x;
            id[i].push_back(idx++);
            map[i].push_back(x);
        }
    }
    for (int i = 1;i < n;++i) {
        for (int j = 0;j < 2 * i + 1;++j) {
            if (j % 2) {
                int x = map[i][j];
                int y = map[i - 1][j - 1];
                int px = id[i][j];
                int py = id[i - 1][j - 1];
                if (y == 4 && x == 2 || y == 3 && x == 1 || y == 2 && x == 4 || y == 1 && x == 3) {
                    adj[px].push_back(py);
                    adj[py].push_back(px);
                }
            }
            else {
                int x = map[i][j];
                int px = id[i][j];
                if (j) {
                    int y = map[i][j - 1];
                    int py = id[i][j - 1];
                    if (y == 3 && x == 2 || y == 4 && x == 1 || y == 2 && x == 3 || y == 1 && x == 4) {
                        adj[px].push_back(py);
                        adj[py].push_back(px);
                    }
                }
                if (j < 2 * i) {
                    int y = map[i][j + 1];
                    int py = id[i][j + 1];
                    if (y == 3 && x == 4 || y == 2 && x == 1 || y == 4 && x == 3 || y == 1 && x == 2) {
                        adj[px].push_back(py);
                        adj[py].push_back(px);
                    }
                }
            }
        }
    }
    std::vector<int> dis(2 * n * n, inf);
    std::priority_queue<a2, std::vector<a2>, std::greater<a2>> pq;
    pq.push({ 0, 0 });
    dis[0] = 0;
    while (pq.size()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (dis[u] != d) continue;
        // std::cout << u << ' ' << d << '\n';
        for (auto v : adj[u]) {
            if (dis[v] > d + 1) {
                dis[v] = d + 1;
                pq.push({ v, d + 1 });
            }
        }
    }
    int x, y;std::cin >> x >> y;x--, y--;
    std::cout << (dis[id[x][y]] == inf ? -1 : dis[id[x][y]]);
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