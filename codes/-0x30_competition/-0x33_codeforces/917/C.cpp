#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int nums[MAXN], v[MAXN];

void solve() {
    int n, k, d;cin >> n >> k >> d;
    int now = 0;
    for (int i = 1;i <= n;++i) {
        cin >> nums[i];
        if (nums[i] == i)now++;
    }
    for (int i = 1;i <= k;++i)cin >> v[i];
    v[0] = v[k];
    int ret = 0;
    for (int i = 1;i <= min(2 * n + 1, d);++i) {
        ret = max(ret, now + (d - i) / 2);
        int x = v[i % k];
        for (int j = 1;j <= x;++j) {
            if (nums[j] == j)now--;
            nums[j]++;
            if (nums[j] == j)now++;
        }
    }
    cout << ret;
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