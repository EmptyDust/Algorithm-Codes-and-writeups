#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;
using namespace std;
#define int long long

void solve() {
    int n;cin >> n;
    int l = 1, r = 2;
    vector<int> mp(n);
    vector<int> dp(n);
    vector<int> pd(n + 1, 0);
    for (int i = 0;i < n;++i)cin >> mp[i];
    if (n == 1) {
        cout << -1;
        return;
    }
    for (int i = 0;i < n;++i)
    {
        if (mp[i] != l)
        {
            dp[i] = l;
            while (pd[++l] == 1);
            if (l == r && r != n)r++;
        }
        else
        {
            dp[i] = r;
            pd[r] = 1;
            r++;
        }
    }
    if (mp[n - 1] == dp[n - 1])swap(dp[n - 1], dp[n - 2]);
    for (int i = 0;i < n;++i)cout << dp[i] << " ";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}