#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 20, K = 10;
int num[MAXN], f[MAXN][1 << K][1 << K];

int dfs(int pos, int mask, int app, bool lead0, bool lim) {
    if (!pos)return !lead0 && mask == app;
    int& cur = f[pos][mask][app];
    if (!lead0 && !lim && ~cur)return cur;
    int up = lim ? num[pos] : 9, res = 0;
    for (int i = 0;i <= up;++i)
        res += dfs(pos - 1, lead0 && !i ? 0 : mask ^ (1 << i), lead0 && !i ? 0 : i & 1 ? app : app | (1 << i), lead0 && !i, lim && i == up);
    if (!lead0 && !lim)cur = res;
    return res;
}

int solve(int x) {
    int len = 0;
    while (x)num[++len] = x % 10, x /= 10;
    memset(f, -1, sizeof f);
    return dfs(len, 0, 0, 1, 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        int a, b;cin >> a >> b;
        cout << solve(b) - solve(a - 1) << '\n';
    }
    return 0;
}