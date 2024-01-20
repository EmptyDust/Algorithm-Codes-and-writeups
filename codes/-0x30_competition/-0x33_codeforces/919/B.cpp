#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 6e6;
int nums[MAXN];

void solve() {
    int n, k, x;cin >> n >> k >> x;
    int sum = 0;
    for (int i = 0;i < n;++i)cin >> nums[i], sum += nums[i];
    sort(nums, nums + n);reverse(nums, nums + n);
    int i = 0;
    for (;i < x;++i)sum -= 2 * nums[i];
    int ans = sum;
    for (int j = 0;j < k;++j, ++i) {
        sum += nums[j];
        if (i < n)sum -= 2 * nums[i];
        ans = max(ans, sum);
    }
    cout << ans;
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