#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

int p[3][4] = {
    {0, 1, 2, 3},
    {3, 2, 1, 0},
    {1, 0, 3, 2}
};

a2 d[4] = { {0,1}, {-1,0},{0,-1},{1,0} };

void solve() {
    int r, c;std::cin >> r >> c;
    std::vector m(r, std::vector<int>(c));
    int count = 0;
    for (int i = 0;i < r;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < c;++j) {
            if (s[j] == '.')m[i][j] = 0;
            else count++;
            if (s[j] == '\\')m[i][j] = 1;
            if (s[j] == '/')m[i][j] = 2;
        }
    }
    auto get_next = [&](int& x, int& y, int& dir) {
        dir = p[m[x][y]][dir];
        x += d[dir][0], y += d[dir][1];
        };
    auto vaild = [&](int x, int y) { return 0 <= x && x < r && 0 <= y && y < c; };
    std::vector<std::string> ans;
    for (int i = 0;i < r;++i) {
        std::vector vis(r, std::vector<int>(c));
        int x = i, y = 0, dir = 0, cnt = 0;
        while (vaild(x, y)) {
            if (!vis[x][y] && m[x][y])cnt++;
            vis[x][y] = 1;
            get_next(x, y, dir);
        }
        if (cnt == count)ans.push_back("W" + std::to_string(i + 1));
    }
    for (int i = 0;i < r;++i) {
        std::vector vis(r, std::vector<int>(c));
        int x = i, y = c - 1, dir = 2, cnt = 0;
        while (vaild(x, y)) {
            if (!vis[x][y] && m[x][y])cnt++;
            vis[x][y] = 1;
            get_next(x, y, dir);
        }
        if (cnt == count)ans.push_back("E" + std::to_string(i + 1));
    }
    for (int i = 0;i < c;++i) {
        std::vector vis(r, std::vector<int>(c));
        int x = 0, y = i, dir = 3, cnt = 0;
        while (vaild(x, y)) {
            if (!vis[x][y] && m[x][y])cnt++;
            vis[x][y] = 1;
            get_next(x, y, dir);
        }
        if (cnt == count)ans.push_back("N" + std::to_string(i + 1));
    }
    for (int i = 0;i < c;++i) {
        std::vector vis(r, std::vector<int>(c));
        int x = r - 1, y = i, dir = 1, cnt = 0;
        // std::cout << x << " " << y << "\n";
        while (vaild(x, y)) {
            if (!vis[x][y] && m[x][y])cnt++;
            vis[x][y] = 1;
            get_next(x, y, dir);
            // std::cout << x << " " << y << "\n";
        }
        // std::cout << cnt << '\n';
        if (cnt == count)ans.push_back("S" + std::to_string(i + 1));
    }
    std::cout << ans.size() << '\n';
    for (auto x : ans)std::cout << x << ' ';
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