#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 64 + 10, MAXM = 18 + 5, mod = 1e9 + 7;
int n, k, num[MAXN], c[MAXN][MAXN];
map<int, int> f[MAXN][MAXN];

int dfs(int pos, int sum, int lim) {
    if (sum > n || sum + k / 2 * (k - k / 2) * ((1LL << pos) - 1) < n)return 0;
    if (!pos)return sum == n;
    if (f[pos][lim].count(sum))return f[pos][lim][sum];
    int res = 0;
    if (num[pos]) for (int i = 0;i <= lim;++i) for (int j = 0;j <= k - lim;++j)
        res = (res + c[lim][i] * c[k - lim][j] % mod * dfs(pos - 1, sum + (i + j) * (k - i - j) * (1LL << (pos - 1)), i) % mod) % mod;
    else for (int j = 0;j <= k - lim;++j)
        res = (res + c[k - lim][j] * dfs(pos - 1, sum + j * (k - j) * (1LL << (pos - 1)), lim) % mod) % mod;
    return f[pos][lim][sum] = res;
}

int solve(int x) {
    int len = 0;
    while (x)num[++len] = x % 2, x /= 2;
    return dfs(len, 0, k);
}

void initC(int n) {
    memset(c, 0, sizeof c);
    c[0][0] = 1;
    for (int i = 1;i < n;++i) {
        c[i][0] = 1;
        for (int j = 1;j <= i;++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    initC(MAXN);
    int m;
    cin >> n >> m >> k;
    cout << solve(m) << '\n';
    return 0;
}