#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 2e2;
int mp[MAXN][MAXN], qey[MAXN], vit[MAXN];
int p, n;

int ans = INT_MAX;
void dfs(int par, int cal, int ct) {
    if (cal == p) {
        ans = min(ans, ct + mp[par][n - 1]);
        return;
    }
    for (int i = 0;i < p;++i)if (vit[i]) {
        vit[i] = 0;
        dfs(qey[i], cal + 1, ct + mp[par][qey[i]]);
        vit[i] = 1;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n;++j)
            cin >> mp[i][j];
    cin >> p;
    for (int i = 0;i < p;++i)cin >> qey[i], qey[i]--;
    for (int i = 0;i < p;++i)vit[i] = 1;
    for (int i = 0;i < n;++i)
        for (int x = 0;x < n;++x)
            for (int y = 0;y < n;++y)
                mp[x][y] = min(mp[x][i] + mp[i][y], mp[x][y]);
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}