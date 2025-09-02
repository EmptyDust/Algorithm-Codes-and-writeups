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

int addx[4] = { 1, -1, 0, 0 };
int addy[4] = { 0, 0, 1, -1 };

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector now(n, std::vector<int>(m));
    std::vector end(n, std::vector<int>(m));
    std::vector block(n, std::vector<int>(m));
    std::vector vis(n, std::vector<int>(m));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            if (s[j] == '@') now[i][j] = 1;
            if (s[j] == '*') end[i][j] = 1;
            if (s[j] == '!') now[i][j] = end[i][j] = 1;
            if (s[j] == '#') block[i][j] = 1;
        }
    }

    auto vaild = [&](int x, int y) {return 0 <= x && x < n && 0 <= y && y < m && !block[x][y];};

    auto find_a_way = [&](int x, int y, int nx, int ny) {
        std::vector next(n, std::vector<int>(m, -1));
        std::queue<a2> q;
        q.push({ x, y });
        next[x][y] = -2;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int s = 0;s < 4;++s) {
                int nx = x + addx[s];
                int ny = y + addy[s];
                if (!vaild(nx, ny)) continue;
                if (next[nx][ny] != -1) continue;
                next[nx][ny] = s;
                q.push({ nx, ny });
            }
        }
        std::vector<int> res;
        while (x != nx || y != ny) {
            res.push_back(next[nx][ny]);
            int nxt = next[nx][ny] ^ 1;
            nx = nx + addx[nxt];
            ny = ny + addy[nxt];
            // std::cout << nx << ' ' << ny << '\n';
        }
        ranges::reverse(res);
        return res;
        };

    std::vector<a3> ans;
    auto _add = [&](int x, int y, int dir) {
        int nx = x + addx[dir];
        int ny = y + addy[dir];
        ans.push_back({ x, y, dir });
        now[x][y] = 0;
        now[nx][ny] = 1;
        };
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) if (!vis[i][j] && vaild(i, j)) {
            std::vector<a2> cstart, cend, call;
            std::queue<a2> q;
            q.push({ i, j });
            vis[i][j] = 1;
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                if (now[x][y] && end[x][y])call.push_back({ x, y });
                else if (now[x][y])cstart.push_back({ x, y });
                else if (end[x][y])cend.push_back({ x, y });
                for (int s = 0;s < 4;++s) {
                    int nx = x + addx[s];
                    int ny = y + addy[s];
                    // std::cout << nx << ' ' << ny << '\n';
                    if (!vaild(nx, ny)) continue;
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    q.push({ nx, ny });
                }
            }
            if (cstart.size() != cend.size()) {
                std::cout << -1;
                return;
            }
            int sz = cend.size();
            for (int i = 0;i < sz;++i) {
                auto res = find_a_way(cstart[i][0], cstart[i][1], cend[i][0], cend[i][1]);
                std::vector<a3> add;
                int x = cstart[i][0], y = cstart[i][1];
                // std::cout << x << ' ' << y << ' ' << cend[i][0] << ' ' << cend[i][1] << '\n';
                for (int nxt : res) {
                    int nx = x + addx[nxt];
                    int ny = y + addy[nxt];
                    // std::cout << nx << ' ' << ny << ' ' << now[nx][ny] << '\n';
                    if (now[nx][ny]) {
                        add.push_back({ x, y, nxt });
                    }
                    else {
                        _add(x, y, nxt);
                        // std::cout << i << ' ';
                    }
                    x = nx, y = ny;
                }
                ranges::reverse(add);
                for (auto [x, y, nxt] : add) _add(x, y, nxt);
            }
        }
    }
    std::cout << ans.size() << '\n';
    for (auto [x, y, dir] : ans) {
        std::cout << x + 1 << ' ' << y + 1 << ' ';
        if (dir == 0) std::cout << 'D';
        if (dir == 1) std::cout << 'U';
        if (dir == 2) std::cout << 'R';
        if (dir == 3) std::cout << 'L';
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}