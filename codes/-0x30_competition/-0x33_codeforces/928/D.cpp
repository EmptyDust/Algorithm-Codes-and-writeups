#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10, m = ((int)1 << 31) - 1;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    int ans = n;
    map<int, int> mp;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        //cout << m - nums[i] << endl;
        if (mp.count(m - nums[i]) && mp[m - nums[i]]) {
            ans--;
            mp[m - nums[i]]--;
        }
        else mp[nums[i]]++;
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