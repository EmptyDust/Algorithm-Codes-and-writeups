#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n, x, y;cin >> n >> x >> y;
    for (int i = 0;i < n;++i)cin >> nums[i];
    map<pt, int> mp;
    int ans = 0;
    for (int i = 0;i < n;++i) {
        int a = nums[i] % x, b = nums[i] % y;
        pt p = { a,b };
        ans += mp[p];
        mp[{(x - a) % x, b% y}]++;
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