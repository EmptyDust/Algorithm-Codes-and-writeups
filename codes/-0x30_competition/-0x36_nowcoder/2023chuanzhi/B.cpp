#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int gcd = nums[0];
    for (int i = 1;i < n;++i) {
        gcd = __gcd(gcd, nums[i]);
        if (gcd == 1)break;
    }
    int ans = 0;
    for (int i = 0;i < n;++i) {
        ans += nums[i] / gcd;
    }
    cout << ans - n;
    return 0;
}