#include <bits/stdc++.h>
#define int long long
using namespace std;

using mi = map<multiset<int>, int>;

constexpr int MAXN = 18 + 10;
int num[MAXN];
mi f[MAXN];

int cal(map<int, int>& mp, bool lead0) {
    if (lead0)return 1;
    int ans = -1;
    for (auto [n, cnt] : mp)
        ans = max(ans, cnt);
    return ans;
}

int dfs(int pos, map<int, int>& mp, bool lead0, bool lim) {
    if (!pos)return cal(mp, lead0);
    multiset<int> mst;
    for (auto [n, cnt] : mp)
        mst.insert(cnt);
    if (!lim && !lead0 && f[pos].count(mst))return f[pos][mst];
    int up = lim ? num[pos] : 9, res = 0;
    for (int i = 0;i <= up;++i) {
        if (!lead0 || i)mp[i]++;
        res += dfs(pos - 1, mp, lead0 && !i, lim && i == up);
        if (!lead0 || i)mp[i]--;
    }
    if (!lim && !lead0)f[pos][mst] = res;
    return res;
}

int solve(int x) {
    int len = 0;
    while (x)num[++len] = x % 10, x /= 10;
    map<int, int> cntmp;
    return dfs(len, cntmp, 1, 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        int l, r;cin >> l >> r;
        cout << solve(r) - solve(l - 1) << '\n';
    }
    return 0;
}