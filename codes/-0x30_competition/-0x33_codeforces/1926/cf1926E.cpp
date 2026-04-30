#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n, k;cin >> n >> k;
    int l = 0, s = n % 2, len = n / 2 + s, level = 0;
    while (l + len < k) {
        l += len;
        n -= len;
        s = n % 2;
        len = n / 2 + s;
        level++;
    }
    int ans = 1 << level;
    //cout << ans << endl;
    ans += (k - l - 1) * (1 << (level + 1));
    cout << ans;
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