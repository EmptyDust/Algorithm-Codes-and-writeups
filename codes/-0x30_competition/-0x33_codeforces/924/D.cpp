#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], f[MAXN];
using pt = pair<int, int>;
int n, b, x;

int cal(int s) {
    int ret = -(s - 1) * x;
    for (int i = 0;i < n;++i) {
        if (nums[i] < s)return ret + f[i];
        int num = nums[i] / s, y = nums[i] % s;
        ret += (num * (nums[i] - num) * (s - y) + (num + 1) * (nums[i] - num - 1) * y) / 2 * b;
        //cout << ret << ' ';
    }
    return ret;
}

void solve() {
    int ans = 0;
    cin >> n >> b >> x;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
    }
    sort(nums, nums + n, [&](int a, int b) {return a > b;});
    for (int i = 0;i < n;++i)f[i] = nums[i] * (nums[i] - 1) / 2 * b;
    for (int i = n - 2;i >= 0;--i)f[i] += f[i + 1];
    for (int i = 1;i <= nums[0];++i) {
        ans = max(cal(i), ans);
        //cout << "#" << i << ' ' << ans << endl;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    signed t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}