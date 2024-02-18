#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int l = 0, r = n - 1;
    while (l < n && nums[l] == nums[0])l++;
    while (r >= 0 && nums[r] == nums[n - 1])r--;
    int ans;
    if (nums[0] == nums[n - 1]) {
        ans = r - l + 1;
    }
    else ans = n - max(l, n - r - 1);
    cout << max((int)0, ans);
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