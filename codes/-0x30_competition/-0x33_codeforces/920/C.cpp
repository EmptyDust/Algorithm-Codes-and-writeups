#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

void solve() {
    int n, f, a, b;cin >> n >> f >> a >> b;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int cur = 0;
    for (int i = 0;i < n;++i) {
        f -= min((nums[i] - cur) * a, b);
        cur = nums[i];
    }
    cout << (f > 0 ? "YES" : "NO");
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