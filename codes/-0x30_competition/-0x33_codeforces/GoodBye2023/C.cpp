#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int nums[MAXN], v[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    cout << nums[0] << ' ';
    int cnt = (nums[0] & 1);
    int sum = nums[0];
    for (int i = 1;i < n;++i) {
        sum += nums[i];
        if (nums[i] & 1)cnt++;
        int res = sum - cnt / 3 - (cnt % 3 == 1);
        cout << res << ' ';
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