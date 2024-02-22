#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n, f[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i], f[i] = INT_MAX;
    f[0] = 0;
    for (int i = 0;i < n;++i) {
        for (int j = max((int)0, i - nums[i]);j <= i;++j)
            f[i] = min(f[i], nums[j] + 1);
        f[i]++;
        for (int j = i + 1;j < min(n, i + nums[i]);++j)
            f[j] = min(f[j], f[i] + 1);
    }
    //for (int i = 0;i < n;++i)cout << f[i] << ' ';
    //cout << endl;
    cout << f[n - 1];
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