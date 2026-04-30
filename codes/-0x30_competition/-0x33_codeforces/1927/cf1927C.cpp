#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int a[MAXN], b[MAXN];
using pt = pair<int, int>;

void solve() {
    int n, m, k;cin >> n >> m >> k;
    for (int i = 0;i < n;++i)cin >> a[i];
    for (int j = 0;j < m;++j)cin >> b[j];
    sort(a, a + n);
    sort(b, b + m);
    int t = 1, acnt = 0, bcnt = 0, cnt = 0;
    for (int i = 0, j = 0;t <= k && (i < n || j < m);++t) {
        while (i < n && a[i] < t)i++;
        while (j < m && b[j] < t)j++;
        if (i < n && j < m && a[i] == t && b[j] == t)continue;
        else if (i < n && a[i] == t)acnt++;
        else if (j < m && b[j] == t)bcnt++;
        else break;
    }
    cout << (t - 1 == k && acnt <= k / 2 && bcnt <= k / 2 ? "Yes" : "No");
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