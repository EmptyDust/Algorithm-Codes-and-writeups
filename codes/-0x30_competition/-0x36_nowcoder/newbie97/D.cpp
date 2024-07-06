#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9;
using pii = std::pair<int, int>;
using a4 = std::array<int, 4>;

int n, m, p;
bool check(pii in) {
    auto& [x, y] = in;
    return 0 <= x && x < n && 0 <= y && y < m;
}

int vis[10][10][10000];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::memset(vis, -1, sizeof vis);
    std::cin >> n >> m >> p;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (auto& vt : a)for (auto& x : vt)std::cin >> x, x %= p - 1;
    std::vector<std::vector<int>> b(n, std::vector<int>(m));
    for (auto& vt : b)for (auto& x : vt)std::cin >> x;

    std::priority_queue<a4, std::vector<a4>, std::greater<a4>> pq;
    pii dir[4] = { {0, 1}, { 0,-1 }, {1,0},{-1,0} };
    pq.push({ 0,a[0][0],0,0 });
    while (pq.size()) {
        auto [dis, cur, x, y] = pq.top();
        pq.pop();
        if (~vis[x][y][cur])continue;
        vis[x][y][cur] = dis;
        for (int i = 0;i < 4;++i) {
            int nx = x + dir[i].first, ny = y + dir[i].second;
            if (check({ nx,ny }) && vis[nx][ny][(cur + a[nx][ny]) % (p - 1)] == -1) {
                pq.push({ dis + 1,(cur + a[nx][ny]) % (p - 1) ,nx,ny });
            }
        }
    }
    std::cout << vis[n - 1][m - 1][0];
    return 0;
}