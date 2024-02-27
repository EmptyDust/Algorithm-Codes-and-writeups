#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
int ans[MAXN];
vector<int> adj[MAXN];

void solve() {
    int n, s, k;cin >> n >> s >> k;
    //cout << n << endl << s << endl << k << endl;
    if (k == 0) {
        for (int i = 0;i < n - 1;++i)cout << 1 << ' ';
        cout << s - (n - 1);
        return;
    }
    if (1 + 2 * k > n || k + 1 + n > s) {
        cout << -1;
        return;
    }
    vector<int> ans(n, 1);
    int x = (s - n) / (k + 1);
    if (1 + 2 * k < n)x = 1;
    for (int i = 0;i <= 2 * k;i += 2)
        ans[i] += x;
    int y = s - n - (k + 1) * x;
    //cout << y << endl;
    if (2 * k + 1 < n) {
        ans[2 * k + 1] += y;
    }
    else {
        for (int& num : ans)if (num == 1) {
            num += min(y, x - 1);
            y -= min(y, x - 1);
            if (!y)break;
        }
    }
    int sum = accumulate(ans.begin(), ans.end(), 0);
    if (sum == s)
        for (int num : ans)cout << num << ' ';
    else
        cout << -1;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    //cout << t << endl;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}