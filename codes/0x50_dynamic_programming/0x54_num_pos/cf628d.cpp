#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 2000 + 100, mod = 1e9 + 7;
int m, d, num[MAXN], f[MAXN][MAXN][2];

int dfs(int pos, int sum, bool iseven, bool lead0, bool lim) {
    if (!pos)return !lead0 && !sum;
    int& cur = f[pos][sum][iseven];
    if (!lead0 && !lim && ~cur)return cur;
    int up = lim ? num[pos] : 9, res = 0;
    if (iseven && d <= up)
        res = (res + dfs(pos - 1, (sum * 10 + d) % m, lead0 && !d ? 0 : !iseven, lead0 && !d, lim && d == up)) % mod;
    if (!iseven)for (int i = 0;i <= up;++i)if (i != d || lead0 && d == 0)
        res = (res + dfs(pos - 1, (sum * 10 + i) % m, lead0 && !i ? 0 : !iseven, lead0 && !i, lim && i == up)) % mod;
    if (!lead0 && !lim)cur = res;
    return res;
}

int solve(string& x, bool minus) {
    int len = 0;
    for (int j = x.length() - 1;~j;--j)
        num[++len] = x[j] - '0';
    if (minus)for (int i = 1;i <= len;++i) {
        if (num[i] == 0)num[i] = 9;
        else {
            num[i]--;
            break;
        }
    }
    memset(f, -1, sizeof f);
    return dfs(len, 0, 0, 1, 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> m >> d;
    string a, b;cin >> a >> b;
    int l = solve(a, true);
    int r = solve(b, false);
    cout << (r - l + mod) % mod << '\n';
    return 0;
}