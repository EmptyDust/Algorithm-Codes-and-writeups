#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    int ans = 0;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        ans = (ans / nums[i] + 1) * nums[i];
        //cout << ans << ' ';
    }
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