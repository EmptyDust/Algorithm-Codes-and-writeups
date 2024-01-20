#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6, Maxlg = 63;
int ans[MAXN], qpow2[Maxlg];
using pt = pair<int, int>;

int plog2(int x) {
    for (int i = 0;i < Maxlg;++i)if (qpow2[i] > x)return i - 1;
    return -1;
}

void solve() {
    int x;cin >> x;
    int ani = 0, cut = 0, t = 2;
    while (t <= x) {
        ans[ani] = cut;
        cut++, ani++;
        t <<= 1;
    }
    t >>= 1;
    x -= t;
    while (x) {
        int l = plog2(x);
        ans[ani++] = l;
        x -= qpow2[l];
    }
    if (ani > 200) {
        cout << -1;
        return;
    }
    cout << ani << '\n';
    for (int i = 0;i < ani;++i)cout << ans[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int a = 1;qpow2[0] = 1;
    for (int i = 1;i < Maxlg;++i) {
        qpow2[i] = qpow2[i - 1] * 2;
    }
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}