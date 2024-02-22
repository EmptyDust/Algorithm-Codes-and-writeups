#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e3 + 10, mod = 1e9 + 7;
int mp[MAXN][MAXN], dp[MAXN];
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int h, w;cin >> h >> w;
    string s;
    dp[1] = 1;
    for (int i = 1;i <= h;++i) {
        cin >> s;s = '*' + s;
        for (int j = 1;j <= w;++j)
            dp[j] = s[j] == '.' ? (dp[j] + dp[j - 1]) % mod : 0;
    }
    cout << dp[w];
    return 0;
}