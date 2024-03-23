#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    cin >> n;
    vector<int> mp(n, 0);
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        mp[nums[i]]++;
    }
    int ans = -1;
    for (int i = 0;i < n;++i)if (!mp[i]) {
        ans = i;
        break;
    }
    if (ans == -1) {
        cout << ans << '\n';
        return;
    }
    vector<pt> res;
    int l = 0, r = 0, ccnt = 0;
    map<int, int> cnt;
    while (r < n) {
        cnt[nums[r]]++;
        if (nums[r] < ans && cnt[nums[r]] == 1)ccnt++;
        if (ccnt == ans) {
            res.push_back({ l, r });
            l = ++r;
            cnt.clear();
            ccnt = 0;
        }
        else r++;
    }
    if (res.size() <= 1) {
        cout << -1 << '\n';
        return;
    }
    res[res.size() - 1].second = n - 1;
    cout << res.size() << '\n';
    for (auto [l, r] : res) {
        cout << l + 1 << ' ' << r + 1 << '\n';
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