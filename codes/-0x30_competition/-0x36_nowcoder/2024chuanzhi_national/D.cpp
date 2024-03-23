#include<bits/stdc++.h>
constexpr int MAXN = 1e6 + 10;
int nums[MAXN];
using i64 = long long;
using pt = std::pair<int, int>;
int n, m;

pt p[4] = { {1,0},{-1,0},{0,1},{0,-1} };
bool valid(int a, int b) { return 0 <= a && a < n && 0 <= b && b < m; }

bool check(std::vector<std::vector<int>>& map) {
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j)if (!map[i][j])
        return false;
    return true;
}

bool dfs(std::vector<std::vector<int>>& map, int x, int y) {
    map[x][y] = 1;
    int cnt = 0;
    for (int i = 0;i < 4;++i) {
        int a = x + p[i].first, b = y + p[i].second;
        if (valid(a, b) && !map[a][b]) {
            if (dfs(map, a, b))return true;;
            cnt++;
        }
    }
    if (!cnt && check(map))return true;
    map[x][y] = 0;
    return false;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    int x, y;
    std::cin >> x >> y;x--, y--;
    std::vector<std::vector<int>> map(n, std::vector<int>(m, 0));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < m;++j)map[i][j] = s[j] == '#';
    }
    bool res = dfs(map, x, y);
    std::cout << (res ? "YES" : "NO");
    return 0;
}