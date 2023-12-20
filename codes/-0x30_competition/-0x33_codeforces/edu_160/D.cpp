#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 998244353;
int nums[MAXN], stk[MAXN], rs[MAXN], ls[MAXN], n, t, top;
using pt = pair<int, int>;

int sted(int l, int r, int i) {
    if (l > r || i == -1)return 1;
    //cout << i << endl;
    int lf = sted(l, i - 1, ls[i]) % mod;
    int rf = sted(i + 1, r, rs[i]) % mod;
    //if (i == 2)cout << rs[i] << endl;
    int ret = (lf * rf) % mod;
    if (l != 0)ret += rf;
    if (r != n - 1)ret += lf;
    if (l != 0 && r != n - 1)ret--;
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int i = 0;i < n;++i)rs[i] = -1;
    for (int i = 0;i < n;++i)ls[i] = -1;
    top = 0;
    for (int i = 0; i < n; i++) {
        int k = top;
        while (k > 0 && nums[stk[k - 1]] > nums[i]) k--;
        if (k) rs[stk[k - 1]] = i;  // rs代表笛卡尔树每个节点的右儿子
        if (k < top) ls[i] = stk[k];  // ls代表笛卡尔树每个节点的左儿子
        stk[k++] = i;
        top = k;
    }
    cout << sted(0, n - 1, stk[0]) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
