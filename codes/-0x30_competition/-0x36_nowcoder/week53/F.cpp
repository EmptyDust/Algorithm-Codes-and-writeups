#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e3 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

int n, m;
bool vaild(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
int map[MAXN][MAXN];
bool vis[MAXN][MAXN];
int map1[MAXN][MAXN];
int map2[MAXN][MAXN];

int dirx[4] = { 1,-1,0,0 };
int diry[4] = { 0,0,1,-1 };
void bfs(int mp[MAXN][MAXN], bool vis[MAXN][MAXN], int lim, int x, int y) {
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        mp[i][j] = -1;
        vis[i][j] = false;
    }
    std::queue<a3> q;
    q.push({ x,y,0 });
    while (q.size()) {
        auto [x, y, d] = q.front();
        q.pop();
        if (vis[x][y] || !map[x][y])continue;
        vis[x][y] = 1;
        mp[x][y] = d;
        for (int i = 0;i < 4;++i)if (i != lim) {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if (vaild(nx, ny))
                q.push({ nx,ny,d + 1 });
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            map[i][j] = s[j] == '.';
        }
    }
    bfs(map1, vis, -1, 0, 0);
    int ans = inf;
    if (vis[n - 1][m - 1]) {
        ans = std::min(ans, map1[n - 1][m - 1]);
    }
    bfs(map1, vis, 3, 0, 0);
    bfs(map2, vis, 2, n - 1, m - 1);
    auto update = [&](int x, int y, int dx, int dy) {
        int nx = x + dx, ny = y + dy;
        if (!vaild(nx, ny))return;
        if (map1[x][y] == -1 || map2[nx][ny] == -1)return;
        ans = std::min(ans, map1[x][y] + map2[nx][ny] + 2);
        };
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        update(i, j, 0, 2);
        update(i, j, 2, 0);
        update(i, j, -2, 0);
        // std::cout << i << ' ' << j << ' ' << ans << '\n';
        update(i, j, 1, 1);
        update(i, j, -1, 1);
    }
    bfs(map1, vis, 1, 0, 0);
    bfs(map2, vis, 0, n - 1, m - 1);
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        update(i, j, 2, 0);
        update(i, j, 0, 2);
        update(i, j, 0, -2);
        update(i, j, 1, 1);
        update(i, j, 1, -1);
    }
    std::cout << (ans == inf ? -1 : ans);
    return 0;
}