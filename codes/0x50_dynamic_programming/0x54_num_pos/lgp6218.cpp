#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 128;
int f[MAXN][MAXN], num[MAXN * 2];

int dfs(int pos, int cnt, bool lead0, bool lim) {
    if (!pos)return !lead0 && cnt > 0;
    int& cur = f[pos][cnt + MAXN];
    if (!lead0 && !lim && ~cur)return cur;
    int up = lim ? num[pos] : 1, res = 0;
    for (int i = 0;i <= up;++i) {
        int add = (i == 0 ? 1 : -1);
        if (lead0) add = 0;
        res += dfs(pos - 1, cnt + add, lead0 && !i, lim && i == up);
    }
    if (!lead0 && !lim)cur = res;
    return res;
}

int solve(int x) {
    int len = 0;
    while (x)num[++len] = x & 1, x >>= 1;
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