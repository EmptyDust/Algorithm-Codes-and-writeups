#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 2e5;
int nums[MAXN];

void solve() {
    int n, k;cin >> n >> k;
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int i = 0;i < n;++i)if (nums[i] % k == 0) {
        cout << 0;
        return;
    }
    int ans = k - 1;
    for (int i = 0;i < n;++i)ans = min(ans, k - nums[i] % k);
    if (k != 4)
        cout << ans;
    if (k == 4) {
        int cnt = 0;
        for (int i = 0;i < n;++i)if (nums[i] % 2 == 0)cnt++;
        if (cnt >= 2) {
            cout << 0;
            return;
        }
        if (cnt == 1) {
            if (n == 1)
                cout << 2;
            else
                cout << 1;
            return;
        }
        if (n == 1)
            cout << (4 - nums[0] % 4);
        else
            cout << min(ans, (int)2);
        return;
    }
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