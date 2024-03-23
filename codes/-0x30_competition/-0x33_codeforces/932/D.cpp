#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n, c;cin >> n >> c;
    int odd = 0, even = 0;
    int d = 0;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        d += c + 1 - (nums[i] - nums[i] / 2);
        if (nums[i] & 1)odd++;
        else even++;
        //cout << c - (nums[i] - nums[i] / 2) << endl;
    }
    int d2 = odd * (odd - 1) / 2 + even * (even - 1) / 2;
    d -= d2;
    int ans = (c + 1 + 1) * (c + 1) / 2 - d;
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