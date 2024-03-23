#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
const int N = 2e5 + 10, mod = 1e9 + 7, inf = 2e18;
typedef pair<int, int> PII;
typedef array<int, 3> arr;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    for (int i = 29; i >= 0; i--) {
        ans |= (1 << i);
        queue<PII> q;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                vis[i][j] = 0;
            }
        }
        q.push({ 1, 1 });
        vis[1][1] = true;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int x1 = x + dx[j], y1 = y + dy[j];
                if (x1 && x1 <= n && y1 && y1 <= m && (a[x1][y1] & ans) == ans && !vis[x1][y1]) {
                    vis[x1][y1] = 1;
                    q.push({ x1, y1 });
                    if (x1 == n && y1 == m) {
                        ans ^= 1 << i;
                        break;
                    }
                }
            }
        }
        ans ^= 1 << i;
    }
    cout << ans << endl;
}
int main() {
    //freopen("title.in","r",stdin);
    //freopen("title.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}