#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 3e5;
int pre[MAXN], suf[MAXN], stk[MAXN], que[MAXN];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> pre[i];
    for (int i = 0; i < n; i++)cin >> suf[i];

    int ski = 0, skj = 0, qei = 0, qej = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre[i] > suf[i] || qei != qej && (que[qei - 1] > suf[i] || que[qej] < pre[i])) {
            cout << "NO";
            return;
        }
        while (ski > skj && stk[ski - 1] <= pre[i])
            ski--;
        stk[ski++] = pre[i];
        que[qei++] = suf[i];
        while (qej < qei && skj < ski) {
            if (que[qej] == stk[skj])
                qej++;
            else
                skj++;
        }
    }
    cout << (qej == qei ? "YES" : "NO");
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
