#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 128, mod = 1e7 + 7;
int len, num[MAXN], f[MAXN][MAXN];

int dfs(int pos, int sum, bool lead0, bool lim) {
    if (!pos)return lead0 ? 1 : sum;
    int& cur = f[pos][sum];
    if (!lead0 && !lim && ~cur)return cur;
    int up = lim ? num[pos] : 1, res = 1;
    for (int i = 0;i <= up;++i)
        res = (res * dfs(pos - 1, sum + i, lead0 && !i, lim && i == up)) % mod;
    if (!lead0 && !lim)cur = res;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;cin >> n;
    while (n)num[++len] = n & 1, n >>= 1;
    memset(f, -1, sizeof f);
    cout << dfs(len, 0, 1, 1);
    return 0;
}