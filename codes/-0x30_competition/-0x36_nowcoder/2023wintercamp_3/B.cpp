#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int cnt = 0;
    if ((nums[0] + nums[n - 1]) % 2 == 0)cnt++;
    for (int i = 1;i < n;++i)if ((nums[i] + nums[i - 1]) % 2 == 0)cnt++;
    cout << (cnt % 2 == 1 ? "qcjj" : "zn");
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