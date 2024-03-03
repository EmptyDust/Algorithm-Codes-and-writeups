#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    vector<int> as, bs;
    int x = 1;
    while (x <= l && l % x == 0) {
        as.push_back(x);
        x *= a;
    }
    x = 1;
    while (x <= l && l % x == 0) {
        bs.push_back(x);
        x *= b;
    }
    vector<int> ans;
    for (int x : as)for (int y : bs)if (l % (x * y) == 0)ans.push_back(l / x / y);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size();
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