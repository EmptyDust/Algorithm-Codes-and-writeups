#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], k[MAXN];
using pt = pair<int, int>;

void solve() {
    int n, m;cin >> n >> m;
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int i = 0;i < m;++i)cin >> k[i];
    sort(nums, nums + n);
    sort(k, k + m);reverse(k, k + m);
    int cur = 0;
    for (int i = 0;i < n;++i)cur += abs(k[i] - nums[i]);
    int ans = cur;
    for (int i = n - 1, j = m - 1;i >= 0;--i, --j) {
        cur += abs(nums[i] - k[j]) - abs(nums[i] - k[i]);
        ans = max(ans, cur);
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