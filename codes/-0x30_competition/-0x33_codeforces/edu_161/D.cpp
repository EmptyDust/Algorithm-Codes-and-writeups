#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int def[MAXN], att[MAXN], pre[MAXN], suf[MAXN], ans[MAXN], n, ani;
bool alive[MAXN];
using pt = pair<int, int>;

bool check(int x) {
    if (x >= n || x < 0)return false;
    if (!alive[x])return false;
    int at = 0;
    if (pre[x] != -1)at += att[pre[x]];
    if (suf[x] != n)at += att[suf[x]];
    return at > def[x];
}

vector<int> rd(vector<int>& leave) {
    ans[ani++] = leave.size();
    vector<int> ret;
    for (int num : leave) {
        alive[num] = false;
        if (pre[num] != -1)suf[pre[num]] = suf[num];
        if (suf[num] != n)pre[suf[num]] = pre[num];
    }
    for (int num : leave) {
        int sf = suf[num];
        if (check(sf))ret.push_back(sf), alive[sf] = false;
        int pr = pre[num];
        if (check(pr))ret.push_back(pr), alive[pr] = false;
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0;i < n;++i)cin >> att[i];
    for (int i = 0;i < n;++i)cin >> def[i];
    for (int i = 0;i < n;++i)alive[i] = true;
    iota(pre, pre + n, -1);
    iota(suf, suf + n, 1);
    ani = 0;

    vector<int> leave;
    for (int i = 0;i < n;++i)if (check(i))
        leave.push_back(i), alive[i] = false;

    for (int i = 0;i < n;++i)leave = rd(leave);

    for (int i = 0;i < n;++i)cout << ans[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}