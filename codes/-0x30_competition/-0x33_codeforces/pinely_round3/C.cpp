#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
constexpr int MAXN = 5e6 + 10;
int l[MAXN], r[MAXN], w[MAXN], ans[MAXN], stk[MAXN];
int t, n, sti, ansi;

void solve() {
    cin >> n;
    for (int i = 0;i < n;++i)cin >> l[i];
    for (int i = 0;i < n;++i)cin >> r[i];
    for (int i = 0;i < n;++i)cin >> w[i];
    sort(l, l + n);
    sort(r, r + n);
    sort(w, w + n, [&](int a, int b) {return a > b;});
    sti = 0, ansi = 0;
    for (int i = 0, j = 0;j < n;++j) {
        while (i < n && l[i] < r[j])stk[sti++] = l[i++];
        ans[ansi++] = r[j] - stk[sti - 1];
        sti--;
    }
    sort(ans, ans + n);
    int sum = 0;
    for (int i = 0;i < n;++i) {
        sum += ans[i] * w[i];
    }
    cout << sum;
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