#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;
constexpr int mod = 1e9 + 7;
using pt = pair<int, int>;
int a[MAXN], b[MAXN], nums[MAXN], zbs[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> a[i];
    for (int i = 0;i < n;++i)cin >> b[i];
    for (int i = 0;i < n;++i)nums[i] = a[i] + b[i];
    iota(zbs, zbs + n, 0);
    sort(zbs, zbs + n, [&](int a, int b) {return nums[a] > nums[b];});
    bool f = true;int asum = 0, bsum = 0;
    for (int i = 0;i < n;++i) {
        if (i & 1)
            bsum += b[zbs[i]] - 1;
        else
            asum += a[zbs[i]] - 1;
    }
    cout << asum - bsum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}