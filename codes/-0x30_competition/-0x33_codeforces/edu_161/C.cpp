#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN], pre[MAXN], suf[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    pre[0] = 0;
    for (int i = 1;i < n;++i) {
        if (i == 1 || nums[i - 1] - nums[i - 2] > nums[i] - nums[i - 1])
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = pre[i - 1] + nums[i] - nums[i - 1];
    }
    suf[n - 1] = 0;
    for (int i = n - 2;i >= 0;--i) {
        if (i == n - 2 || nums[i + 2] - nums[i + 1] > nums[i + 1] - nums[i])
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = suf[i + 1] + nums[i + 1] - nums[i];
    }
    int m;cin >> m;
    while (m--) {
        int f, d;cin >> f >> d;f--, d--;
        if (d > f)cout << pre[d] - pre[f];
        else cout << suf[d] - suf[f];
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}