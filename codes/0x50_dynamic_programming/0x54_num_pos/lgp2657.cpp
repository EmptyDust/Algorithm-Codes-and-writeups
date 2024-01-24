#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 9 + 10;
int num[MAXN], f[MAXN][MAXN];

int dfs(int pos, int pre, bool lead0, bool lim) {
    if (!pos)return !lead0;
    int& cur = f[pos][pre];
    if (!lead0 && !lim && ~cur)return cur;
    int up = lim ? num[pos] : 9, res = 0;
    for (int i = 0;i <= up;++i)if (lead0 || abs(pre - i) >= 2)
        res += dfs(pos - 1, i, lead0 && !i, lim && i == up);
    if (!lead0 && !lim)cur = res;
    return res;
}

int solve(int x) {
    int len = 0;
    while (x)num[++len] = x % 10, x /= 10;
    memset(f, -1, sizeof f);
    return dfs(len, 0, 1, 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int a, b;cin >> a >> b;
    int l = solve(a - 1);
    int r = solve(b);
    cout << r - l;
    return 0;
}