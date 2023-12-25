#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
constexpr int MAXN = 5e6 + 10;
int nums[MAXN];
int t, n, k;

int sgn(int x) {
    if (x > 0)return 1;
    if (x < 0)return -1;
    return 0;
}

void solve() {
    cin >> n >> k;
    for (int i = 0;i < n;++i)cin >> nums[i], nums[i] -= k;
    int tmp = sgn(nums[0]);
    for (int i = 0;i < n;++i)if (sgn(nums[i]) != tmp) {
        cout << -1;
        return;
    }
    if (tmp == 0) {
        cout << 0;
        return;
    }
    int gcd = nums[0];
    for (int i = 0;i < n;++i)gcd = __gcd(gcd, nums[i]);
    int sum = 0;
    for (int i = 0;i < n;++i)sum += nums[i] / gcd - 1;
    cout << sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}