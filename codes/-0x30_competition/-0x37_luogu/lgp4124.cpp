#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MAXN = 11 + 10;
int num[MAXN], f[MAXN][2][2][2][2], len;

int dfs(int pos, int pre, bool equal, bool con, bool has8, bool has4, bool lead0, bool lim) {
    if (has4 && has8 || pos != 11 && lead0)return 0;
    if (!pos)return con;
    int& cur = f[pos][equal][con][has8][has4];
    if (!lead0 && !lim && ~cur)return cur;
    int up = lim ? num[pos] : 9, res = 0;
    for (int i = 0;i <= up;++i)
        res += dfs(pos - 1, i, pre == i, con || equal && i == pre, has8 || i == 8, has4 || i == 4, lead0 && !i, lim && i == up);
    if (!lead0 && !lim)cur = res;
    return res;
}

int solve(int x) {
    len = 0;
    while (x)num[++len] = x % 10, x /= 10;
    memset(f, -1, sizeof f);
    return dfs(len, -1, -1, 0, 0, 0, 1, 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int l, r;cin >> l >> r;
    cout << solve(r) - solve(l - 1);
    return 0;
}