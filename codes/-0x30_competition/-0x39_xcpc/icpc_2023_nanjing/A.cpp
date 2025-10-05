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

constexpr int dx[4] = { 1, -1, 0, 0 };
constexpr int dy[4] = { 0, 0, 1, -1 };

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector map(n, std::vector<int>(m));
    std::vector vis(n, std::vector<int>(m));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            map[i][j] = s[j] == '.';
        }
    }
    auto vaild = [&](int x, int y) {return 0 <= x && 0 <= y && x < n && y < m;};
    int idx = 0;
    std::vector positions(n * m, std::vector<a2>());
    std::vector<a2> block(n * m);
    std::vector<int> count(n * m);
    auto dfs1 = [&](auto&& dfs1, int x, int y) {
        if (!vaild(x, y)) return;
        if (!map[x][y]) return;
        if (vis[x][y]) return;
        vis[x][y] = 1;
        count[idx]++;
        positions[idx].push_back({ x, y });
        for (int i = 0;i < 4;++i) {
            dfs1(dfs1, x + dx[i], y + dy[i]);
        }
        };
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            if (vis[i][j] || !map[i][j]) continue;
            dfs1(dfs1, i, j);
            block[idx] = { i, j };
            idx++;
        }
    }
    vis.assign(n, std::vector<int>(m));
    std::vector<a2> tmp;
    auto dfs2 = [&](auto&& dfs2, int tx, int ty, int x1, int y1, int x2, int y2)->bool {
        if (!vaild(x1 + tx, y1 + ty)) return true;
        if (!map[x1 + tx][y1 + ty]) return true;
        if (!vaild(x2 + tx, y2 + ty)) return false;
        if (!map[x2 + tx][y2 + ty]) return false;
        if (vis[x2 + tx][y2 + ty]) return true;
        vis[x2 + tx][y2 + ty] = 1;
        tmp.push_back({ x2 + tx, y2 + ty });
        for (int i = 0;i < 4;++i) {
            if (!dfs2(dfs2, tx + dx[i], ty + dy[i], x1, y1, x2, y2)) return false;
        }
        return true;
        };
    int ans = 0;
    for (int i = 0;i < idx;++i) {
        auto [x1, y1] = block[i];
        bool f = 1;
        for (int j = 0;j < idx && f;++j)if (i != j) {
            for (auto [x2, y2] : positions[j]) {
                auto tag = dfs2(dfs2, 0, 0, x1, y1, x2, y2);
                for (auto [x, y] : tmp) {
                    vis[x][y] = 0;
                }
                tmp.clear();
                if (tag) {
                    f = 0;
                    break;
                }
            }
        }
        if (f) ans += count[i];
    }
    std::cout << ans;
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