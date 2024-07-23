#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));

    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int le = 2; le <= n; le++) {
        for (int l = 0; l + le <= n; l++) {
            if (a[l] % 2 != (l + 1) % 2) continue;
            if (a[l] > l + 1) continue;
            int v = (l + 1 - a[l]) / 2;

            int r = l + le;
            for (int m = l + 1; m < r; m += 2) { // index of the closing bracket
                if (dp[l + 1][m] <= v) {
                    int new_val = max(v, dp[m + 1][r] - (m - l + 1) / 2);
                    dp[l][r] = min(dp[l][r], new_val);
                }
            }
        }
    }

    vector<int> dp2(n + 1);
    for (int i = 0; i < n; i++) {
        dp2[i + 1] = dp2[i];

        for (int j = 0; j < i; j++) {
            if (dp[j][i + 1] <= dp2[j]) {
                dp2[i + 1] = max(dp2[i + 1], dp2[j] + (i - j + 1) / 2);
            }
        }
    }
    cout << dp2[n] << nl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}