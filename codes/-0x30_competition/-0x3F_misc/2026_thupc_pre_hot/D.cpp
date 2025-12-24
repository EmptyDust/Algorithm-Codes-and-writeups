#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(next(a.begin()), a.end(), greater<int>());
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    vector<vector<ll>> dp(2, vector<ll>(sum[n] + 1, -1));
    dp[0][0] = 0;
    auto upd = [&](ll& x, ll y) -> void
        {
            x = max(x, y);
        };
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum[i]; j++) {
            dp[1][j] = -1;
        }
        for (int j = 0; j <= sum[i - 1]; j++) {
            if (dp[0][j] == -1)
                continue;
            upd(dp[1][j + a[i]], dp[0][j] + 1ll * (j + a[i]) * (sum[n] - (j + a[i])));
            // cout << i << " " << j << " " << dp[i][j + a[i]] << endl;
            upd(dp[1][j], dp[0][j] + 1ll * (sum[i] - j) * (sum[n] - (sum[i] - j)));
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
        dp[0] = dp[1];
    }

    ll ans = 0;
    for (int i = 0; i <= sum[n - 1]; i++) {
        ans = max(ans, dp[1][i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}