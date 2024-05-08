#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int mp[20][20], vis[20][20];
using pt = std::pair<int, int>;
#define x first
#define y second

pt adj[4] = { {1,0},{0,1},{-1,0},{0,-1} };
bool check(int x, int y) { return 1 <= x && x <= 19 && 1 <= y && y <= 19; }
bool cal(int x, int y, bool f) {
    std::queue<pt> q;
    memset(vis, 0, sizeof vis);
    q.push({ x,y });
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        if (vis[x][y])continue;
        vis[x][y] = 1;
        for (auto& [_x, _y] : adj) {
            int nx = x + _x;
            int ny = y + _y;
            if (check(nx, ny) && !vis[nx][ny] && mp[nx][ny] == f)
                q.push({ nx,ny });
            if (check(nx, ny) && mp[nx][ny] == -1)
                return false;
        }
    }
    return true;
}

int clear(int x, int y, bool f) {
    std::queue<pt> q;
    q.push({ x,y });
    int ret = 1;
    mp[x][y] = -1;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& [_x, _y] : adj) {
            int nx = x + _x;
            int ny = y + _y;
            if (check(nx, ny) && mp[nx][ny] == f) {
                ret++;
                mp[nx][ny] = -1;
                q.push({ nx,ny });
            }
        }
    }
    return ret;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    memset(mp, -1, sizeof mp);
    int n;std::cin >> n;
    int x, y;
    for (int s = 1;s <= n;++s) {
        std::cin >> x >> y;
        bool f;
        if (s & 1) mp[x][y] = f = 1;
        else mp[x][y] = f = 0;
        int res2 = 0, res1 = 0;
        for (auto& [_x, _y] : adj) {
            int nx = x + _x;
            int ny = y + _y;
            if (check(nx, ny) && mp[nx][ny] == !f && cal(nx, ny, !f))
                res2 += clear(nx, ny, !f);
        }
        if (cal(x, y, f))
            res1 += clear(x, y, f);
        if (s & 1) std::cout << res1 << ' ' << res2 << '\n';
        else std::cout << res2 << ' ' << res1 << '\n';
    }
    return 0;
}