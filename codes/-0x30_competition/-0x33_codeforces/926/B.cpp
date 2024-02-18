#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n, k;cin >> n >> k;
    int ans = n * 2 - 2;
    if (ans * 2 >= k) {
        cout << (k + 1) / 2;
        return;
    }
    k -= ans * 2;
    cout << ans + k;
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