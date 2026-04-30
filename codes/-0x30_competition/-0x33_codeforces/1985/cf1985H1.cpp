#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<std::vector<int>> map(n, std::vector<int>(m)), vis(map);
    for (int i = 0;i < n;++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0;j < m;++j) {
            map[i][j] = s[j] == '#';
        }
    }
    pii dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
    auto vaild = [&](int x, int y) {return 0 <= x && x < n && 0 <= y && y < m;};
    std::vector<int> cs(1, 0);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j)if (!vis[i][j] && map[i][j]) {
            int id = cs.size();
            cs.push_back(0);
            std::queue<pii> q;
            q.push({ i,j });
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                if (vis[x][y])continue;
                vis[x][y] = id;
                cs.back()++;
                for (int k = 0;k < 4;++k) {
                    int nx = x + dir[k].first;
                    int ny = y + dir[k].second;
                    if (vaild(nx, ny) && map[nx][ny] && !vis[nx][ny]) {
                        q.push({ nx,ny });
                    }
                }
            }
        }
    }
    int ans = 0;
    auto get = [&](int x, int y) {return vaild(x, y) && map[x][y] ? vis[x][y] : 0;};
    for (int i = 0;i < n;++i) {
        std::set<int> st;
        int res = 0;
        for (int j = 0;j < m;++j) {
            if (!map[i][j]) res++;
            int tmp = get(i, j);
            if (tmp && !st.count(tmp)) {
                st.insert(tmp);
                res += cs[tmp];
            }
            tmp = get(i + 1, j);
            if (tmp && !st.count(tmp)) {
                st.insert(tmp);
                res += cs[tmp];
            }
            tmp = get(i - 1, j);
            if (tmp && !st.count(tmp)) {
                st.insert(tmp);
                res += cs[tmp];
            }
        }
        ans = std::max(ans, res);
    }
    for (int j = 0;j < m;++j) {
        std::set<int> st;
        int res = 0;
        for (int i = 0;i < n;++i) {
            if (!map[i][j]) res++;
            int tmp = get(i, j);
            if (tmp && !st.count(tmp)) {
                st.insert(tmp);
                res += cs[tmp];
            }
            tmp = get(i, j + 1);
            if (tmp && !st.count(tmp)) {
                st.insert(tmp);
                res += cs[tmp];
            }
            tmp = get(i, j - 1);
            if (tmp && !st.count(tmp)) {
                st.insert(tmp);
                res += cs[tmp];
            }
        }
        ans = std::max(ans, res);
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