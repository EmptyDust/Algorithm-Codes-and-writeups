#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], mp[MAXN][20];

void solve() {
    int n;cin >> n;
    for (int i = 1;i <= n;++i)
        cin >> nums[i];
    int cnt = 1;
    for (int i = 1;i < n;++i)if (n % i == 0) {
        bool f = true;
        int gcd = abs(nums[1 + i] - nums[1]);
        for (int j = 1;j <= i;++j) {
            for (int k = j + i;k <= n;k += i) {
                gcd = __gcd(gcd, abs(nums[k] - nums[k - i]));
                if (gcd == 1)break;
            }
        }
        if (gcd != 1)cnt++;
    }
    cout << cnt;
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