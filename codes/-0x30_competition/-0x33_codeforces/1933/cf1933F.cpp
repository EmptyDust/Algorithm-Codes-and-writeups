#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e3 + 10;
int mp[MAXN][MAXN], n, check[MAXN];
using pt = pair<int, int>;

void solve() {
    int m, n;cin >> n >> m;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            cin >> mp[i][j];
        }
        check[i] = 1;
    }
    queue<array<int, 4>> q;
    q.push({ 0,0,n - 1,0 });
    int cnt = 0;
    while (!q.empty()) {
        auto& cur = q.front();
        int x = cur[0] % n, y = cur[1], a = cur[2] % n, t = cur[3];
        q.pop();
        if (mp[x][y] || y >= m)continue;
        if (x == 0 && y == 2)cout << t << endl;
        if (y == m - 1 && x == a) {
            cout << t;
            return;
        }
        x = (x + 1) % n;
        if (!mp[x][y])
            q.push({ x + 1, y, a + 1, t + 1 });
        q.push({ x,y + 1,a + 1,t + 1 });
        q.push({ (x - 1 + n) % n,y,a + 1,t + 1 });
    }
    cout << -1;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}