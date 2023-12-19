#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 998244353;
int nums[MAXN], n, t;
using pt = pair<int, int>;

int sted(int l, int r) {
    if (l > r)return 1;
    if (l == r)return 2;
    int i = min_element(nums + l, nums + r + 1) - nums;
    int lf = sted(l, i - 1) % mod;//左边1
    int rf = sted(i + 1, r) % mod;//右边2
    int ret = (lf * rf) % mod;
    if (l != 0)ret += rf;
    if (r != n - 1)ret += lf;
    if (l != 0 && r != n - 1)ret--;
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    if (n == 1)cout << 1;
    else cout << (sted(0, n - 1)) % mod;
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