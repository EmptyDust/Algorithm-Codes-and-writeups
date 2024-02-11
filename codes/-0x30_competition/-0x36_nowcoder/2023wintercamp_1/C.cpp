#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e5 + 10;
int nums[MAXN], qry[MAXN], zbs[MAXN], ans[MAXN], sums[MAXN];
using pt = pair<int, int>;

void solve() {
    int n, q, t;cin >> n >> q >> t;
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int j = 0;j < q;++j)cin >> qry[j];
    sort(nums, nums + n);
    iota(zbs, zbs + q, 0);
    sort(zbs, zbs + q, [&](int a, int b) {return qry[a] > qry[b];});
    for (int i = 0;i < n;++i)
        sums[i] = (i ? sums[i - 1] : 0) + nums[i];
    for (int j = 0;j < q;++j)ans[j] = sums[n - 1] + t;
    for (int i = 0, j = 0;i < n;++i) {
        while (j < q && qry[zbs[j]] >= (n - i) * t) {
            ans[zbs[j]] = (i ? sums[i - 1] : 0) + t;
            ++j;
        }
    }
    for (int j = 0;j < q;++j)cout << ans[j] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}