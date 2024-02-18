#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;

signed main() {
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    s = '#' + s, t = '$' + t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 1;i < n;++i)for (int j = 1;j < m;++j) {
        if (s[i] == t[j])dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
    int x = n - 1, y = m - 1;
    string ans;
    while (x && y) {
        if (s[x] == t[y])ans += s[x], x--, y--;
        else if (dp[x - 1][y] > dp[x][y - 1])x--;
        else y--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}