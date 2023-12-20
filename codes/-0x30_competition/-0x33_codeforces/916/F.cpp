#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 1e9 + 7;
using pt = pair<int, int>;
int par[MAXN], cnts[MAXN], f[MAXN], sums[MAXN], mxs[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i <= n;++i)cnts[i] = 0, f[i] = 0, sums[i] = 0, mxs[i] = -1;
    par[1] = 0;
    for (int i = 2;i <= n;++i)cin >> par[i], cnts[par[i]]++;
    queue<int> leaves;
    for (int i = 1;i <= n;++i)if (!cnts[i])leaves.push(i);
    while (!leaves.empty()) {
        int num = leaves.front(), p = par[num], tmp = 2 * sums[mxs[num]] - sums[num];

        if (tmp <= 0 || tmp <= sums[mxs[num]] - f[mxs[num]])
            f[num] = sums[num] & 1;
        else
            f[num] = tmp - (sums[mxs[num]] - f[mxs[num]]);

        if (mxs[p] == -1 || sums[mxs[p]]<sums[num] || sums[mxs[p]] == sums[num] && f[mxs[p]]>f[num])mxs[p] = num;
        f[num]++;
        sums[num]++;
        sums[p] += sums[num];

        cnts[p]--;
        if (!cnts[p])leaves.push(p);

        leaves.pop();
    }
    cout << (n - f[1]) / 2;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}