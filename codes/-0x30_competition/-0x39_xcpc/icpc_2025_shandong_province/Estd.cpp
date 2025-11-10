#include <bits/stdc++.h>
#define fir first
#define sec second

using namespace std;
#define int long long

using PII = pair<int, int>;
using ll = long long;

void solve()
{
    ll k;
    int n;
    cin >> n >> k;
    ll S = k;
    vector<int> a(n + 1, 0);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];
        mx = max(mx, a[i]);
    }
    vector<int> sum(mx + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum[a[i]]++;
    }
    for (int i = 1; i <= mx; i++) {
        sum[i] += sum[i - 1];
    }

    vector<int> v;
    for (ll i = 1; i * i <= S; i++) {
        if (S % i == 0) {
            v.push_back(i);
            v.push_back(S / i);
        }
    }

    ll ans = 1;

    for (int i = 0; i < v.size(); i++) {
        ll x = v[i];
        int flag = 0;
        ll tot = 0;
        // cout << x << endl;
        if (x > mx) {
            tot = n * ((mx + x - 1) / x * x);
        }
        else {
            for (int i = 0; i <= mx; i += x) {
                int st = i + 1, ed = i + x;
                ed = min(ed, mx);
                int cnt = sum[ed] - sum[st - 1];
                tot += cnt * (i + x);
            }
        }

        // cout << endl;
        if (tot <= S) {
            flag = 1;
        }
        if (flag) {
            ans = max(ans, x);
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
