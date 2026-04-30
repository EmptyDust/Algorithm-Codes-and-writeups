#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;

void solve() {
    int n;cin >> n;
    vector<int> nums(n);
    for (int i = 0;i < n;++i)cin >> nums[i];
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int ans = 0;
    for (int l = 0, r = 0;r < nums.size();r++) {
        while (nums[r] - nums[l] >= n)l++;
        ans = max(r - l + 1, ans);
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