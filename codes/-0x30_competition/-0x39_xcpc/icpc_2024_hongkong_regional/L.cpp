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

void print(std::vector<std::vector<int>>& map, int n, int m) {
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int find_next(std::vector<std::vector<int>>& map, int i, int m) {
    int ret = -1;
    for (int j = 0;j < m;++j) {
        if (map[i][j] == 0)
            ret = j;
    }
    return ret;
}

bool check(std::vector<std::vector<int>>& map, int n, int m) {
    for (int i = 0;i < n;++i) {
        if (find_next(map, i, m) != -1) return false;
    }
    return true;
}

bool test(std::vector<std::vector<int>> map, int n, int m) {
    // print(map, n, m);
    int cnt = 0;
    std::vector<std::string> ans;
    while (!check(map, n, m) && cnt < 400) {
        cnt++;
        int y = 0;
        std::string line;
        for (int x = 0;x < n - 1;++x) {
            int next = find_next(map, x, m);
            map[x][y] = !map[x][y];
            if (x) line += 'D';
            // std::cout << x << ' ' << y << '\n';
            if (next == -1 || next <= y) continue;
            do {
                y++;
                map[x][y] = !map[x][y];
                line += 'R';
                // std::cout << x << ' ' << y << '\n';
            } while (y < next);
        }
        if (n - 1) line += 'D';
        while (y < m) {
            map[n - 1][y] = !map[n - 1][y];
            if (y != m - 1)line += 'R';
            // std::cout << n - 1 << ' ' << y << '\n';
            y++;
        }
        ans.push_back(line);
        // print(map, n, m);
        // std::cout << line << '\n';
    }
    if (check(map, n, m)) {
        std::cout << "YES\n";
        std::cout << ans.size() << '\n';
        for (auto& res : ans)std::cout << res << '\n';
        return true;
    }
    return false;
}

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector map(n, std::vector<int>(m));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j) {
            map[i][j] = s[j] == 'W';
        }
    }
    if (test(map, n, m))return;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            map[i][j] = !map[i][j];
        }
    }
    if (test(map, n, m))return;
    std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}