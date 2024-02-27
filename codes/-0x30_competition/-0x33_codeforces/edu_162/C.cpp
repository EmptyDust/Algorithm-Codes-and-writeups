#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], sums[MAXN], n, cnt[MAXN];
using pt = pair<int, int>;

void solve() {
    int n, q;cin >> n >> q;
    for (int i = 1;i <= n;++i)cin >> nums[i];
    int cnt1 = 0;
    for (int i = 1;i <= n;++i)cnt[i] = cnt1 += nums[i] == 1;
    int sum = 0;
    for (int i = 1;i <= n;++i)sums[i] = sum += nums[i];
    int l, r;
    while (q--) {
        cin >> l >> r;
        int sum = sums[r] - sums[l - 1];
        int c = cnt[r] - cnt[l - 1];
        int len = r - l + 1;
        int b = sum - len;
        cout << (b >= c && len != 1 ? "YES" : "NO") << '\n';
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