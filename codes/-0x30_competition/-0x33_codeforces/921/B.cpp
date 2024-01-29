#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6, mod = 1e9 + 7;
int n, nums[MAXN];

using pt = pair<int, int>;

void solve() {
    int x, n;cin >> x >> n;
    int ans = 0;
    vector<int> f;
    for (int i = 1;i < 10000;++i) {
        if (x % i)continue;
        if (i * n <= x)ans = max(ans, i);
        if (x / i * n <= x)ans = max(ans, x / i);
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--)solve(), cout << '\n';
    return 0;
}
