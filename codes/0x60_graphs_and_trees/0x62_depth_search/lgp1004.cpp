#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 11;
int n, mp[MAXN][MAXN], res = 0, vis[MAXN][MAXN], f[MAXN][MAXN][MAXN][MAXN];

void dfs(int x1, int y1, int x2, int y2, int num) {
    num += vis[x1][y1] ? 0 : mp[x1][y1];
    vis[x1][y1] = 1;
    num += vis[x2][y2] ? 0 : mp[x2][y2];
    vis[x2][y2] = 1;
    if (num < f[x1][y1][x2][y2]) {
        vis[x1][y1] = vis[x2][y2] = 0;
        return;
    }
    f[x1][y1][x2][y2] = num;
    if (x1 == n && y1 == n && x2 == n && y2 == n) {
        vis[x1][y1] = vis[x2][y2] = 0;
        return;
    }
    if (x1 != n && x2 != n)dfs(x1 + 1, y1, x2 + 1, y2, num);
    if (y1 != n && x2 != n)dfs(x1, y1 + 1, x2 + 1, y2, num);
    if (x1 != n && y2 != n)dfs(x1 + 1, y1, x2, y2 + 1, num);
    if (y1 != n && y2 != n)dfs(x1, y1 + 1, x2, y2 + 1, num);
    vis[x1][y1] = vis[x2][y2] = 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int x, y, num;
    while (cin >> x >> y >> num) {
        if (!x && !y && !num)break;
        mp[x][y] = num;
    }
    dfs(1, 1, 1, 1, 0);
    cout << f[n][n][n][n];
    return 0;
}