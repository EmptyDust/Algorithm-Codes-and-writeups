#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    sort(nums, nums + n);
    int ans = 0, cnt = 1, pre = 0;
    for (int i = 1;i < n;++i) {
        if (nums[i] == nums[i - 1])cnt++;
        else {
            if (cnt > 2) {
                ans += cnt * (cnt - 1) * (cnt - 2) / 6;
            }
            if (cnt > 1) {
                ans += cnt * (cnt - 1) / 2 * pre;
            }
            pre = i;
            cnt = 1;
        }
    }
    if (cnt > 2) {
        ans += cnt * (cnt - 1) * (cnt - 2) / 6;
    }
    if (cnt > 1) {
        ans += cnt * (cnt - 1) / 2 * pre;
    }
    cout << ans;
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