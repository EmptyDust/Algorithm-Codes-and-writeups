#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
constexpr int MAXN = 5e6 + 10;
int nums[MAXN];
int prime[MAXN], pi;
int t, n;

void solve() {
    cin >> n;
    int m = LONG_LONG_MAX;
    for (int i = 0;i < n;++i)cin >> nums[i], m = min(nums[i], m);
    sort(nums, nums + n);
    int gcd = nums[1] - nums[0];
    for (int i = 1;i <= n - 2;++i)
        gcd = __gcd(gcd, nums[i + 1] - nums[i]);
    cout << gcd * 2;
    return;
}

// 5 3 2

signed main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}