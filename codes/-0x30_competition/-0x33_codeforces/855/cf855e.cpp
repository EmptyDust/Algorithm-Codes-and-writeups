#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MAXN = 64 + 10, R = 10 + 1;
int num[MAXN], f[R][MAXN][1 << R], b;

int dfs(int pos, int st, bool lead0, bool lim) {
    if (!pos)return !lead0 && !st;
    int& cur = f[b][pos][st];
    if (!lead0 && !lim && ~cur)return cur;
    int up = lim ? num[pos] : b - 1, res = 0;
    for (int i = 0;i <= up;++i)
        res += dfs(pos - 1, lead0 && i == 0 ? 0 : st ^ (1 << i), lead0 && !i, lim && i == up);
    if (!lead0 && !lim)cur = res;
    return res;
}

int solve(int x) {
    int len = 0;
    while (x)num[++len] = x % b, x /= b;
    return dfs(len, 0, 1, 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    memset(f, -1, sizeof f);
    int q;cin >> q;
    while (q--) {
        int l, r;cin >> b >> l >> r;
        cout << solve(r) - solve(l - 1) << '\n';
    }
    return 0;
}