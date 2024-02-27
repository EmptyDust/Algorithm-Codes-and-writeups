#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10, inf = 1e9;
int n, ans[MAXN], nums[MAXN], pre[MAXN];
using pt = pair<int, int>;

void solve() {
    cin >> n;
    for (int i = 1;i <= n;++i) {
        cin >> nums[i];
        ans[i] = inf;
    }
    nums[n + 1] = 0;
    auto cal = [&](bool re) {
        for (int i = 1;i <= n;++i)
            pre[i] = pre[i - 1] + nums[i];
        pre[n + 1] = 0;
        for (int i = 1, k = 2;i < n;++i) {
            while (k <= n && nums[i + 1] == nums[k])k++;
            int l = i + 1, r = n + 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (pre[mid] - pre[i] > nums[i])r = mid;
                else l = mid + 1;
            }
            l = max(l, k);
            //cout << l << endl;
            if (l <= n) {
                if (!re)
                    ans[i] = min(ans[i], l - i);
                else
                    ans[n - i + 1] = min(ans[n - i + 1], l - i);
            }
            if (nums[i] < nums[i + 1]) {
                if (!re)
                    ans[i] = 1;
                else
                    ans[n - i + 1] = 1;
            }
        }
        };
    cal(false);
    reverse(nums + 1, nums + n + 1);
    cal(true);
    for (int i = 1;i <= n;++i) {
        ans[i] = ans[i] == inf ? -1 : ans[i];
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}