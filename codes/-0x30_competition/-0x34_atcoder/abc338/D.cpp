#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;cin >> n >> m;
    for (int i = 0;i < m;++i)cin >> nums[i], nums[i]--;
    vector<int> mi(n + 1);
    for (int i = 1;i < m;++i) {
        int sen = max(nums[i], nums[i - 1]);
        int jun = min(nums[i], nums[i - 1]);
        int cost = sen - jun;
        int rcost = n - cost;
        mi[jun] += rcost - cost;
        mi[sen] += cost - rcost;
        mi[0] += cost;
    }
    int ans = mi[0];
    for (int i = 1;i < n;++i) {
        mi[i] += mi[i - 1];
        ans = min(mi[i], ans);
    }
    cout << ans;
    return 0;
}