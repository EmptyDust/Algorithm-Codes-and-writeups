#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 18 + 10, mod = 1e9 + 7;
int l[MAXN], r[MAXN], f[MAXN][MAXN * 9];

int dfs(int num[], int pos, int sum, bool lim) {
    if (!pos) return sum;
    int& cut = f[pos][sum];
    if (!lim && ~cut)return cut;
    int up = lim ? num[pos] : 9, res = 0;
    for (int i = 0;i <= up;++i)
        res = (res + dfs(num, pos - 1, sum + i, lim && i == up)) % mod;
    if (!lim)cut = res;
    return res;
}

int solve() {
    int llen = 0, rlen = 0;
    int ln, rn;cin >> ln >> rn;ln--;
    while (ln) l[++llen] = ln % 10, ln /= 10;
    while (rn) r[++rlen] = rn % 10, rn /= 10;
    int ansl, ansr;
    memset(f, -1, sizeof f);
    ansr = dfs(r, rlen, 0, 1);
    memset(f, -1, sizeof f);
    ansl = dfs(l, llen, 0, 1);
    return (ansr - ansl + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}