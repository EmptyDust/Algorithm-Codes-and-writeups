#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct N {
    string t;
    bool k;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;

    vector<N> a(n);
    string dum, s;
    int f = -1, l = -1;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].t >> dum >> s;
        a[i].k = (s == "+");
        if (a[i].k) {
            if (f == -1) f = i;
            l = i;
        }
    }

    vector<int> y(n);
    y[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        y[i] = (a[i].t < a[i + 1].t) ? y[i + 1] : y[i + 1] - 1;
    }

    vector<int> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        if (f != -1 && i > f) break;
        dp[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (dp[i] == INF) continue;
        for (int j = i + 1; j < n; ++j) {
            int gap = (a[i].t < a[j].t) ? 0 : 1;
            if (y[j] - y[i] == gap) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
            if (a[j].k) break;
        }
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (l != -1 && i < l) continue;
        if (y[i] == 0) ans = min(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}