#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], f[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    f[0] = -1;
    for (int i = 1;i < n;++i) {
        if (nums[i] == nums[i - 1]) {
            f[i] = f[i - 1];
        }
        else {
            f[i] = i - 1;
        }
    }
    int q;cin >> q;
    int l, r;
    while (q--) {
        cin >> l >> r;r--, l--;
        if (f[r] >= l)cout << r + 1 << ' ' << f[r] + 1 << '\n';
        else cout << -1 << ' ' << -1 << '\n';
    }
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