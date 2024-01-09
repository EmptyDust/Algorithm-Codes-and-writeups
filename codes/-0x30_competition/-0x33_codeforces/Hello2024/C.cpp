#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int nums[MAXN], v[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int cnt = 0;
    int tmp1, tmp2;
    tmp1 = tmp2 = 0;
    for (int i = 0;i < n;++i) {
        if (nums[i] <= tmp1) {
            tmp1 = nums[i];
        }
        else if (nums[i] <= tmp2) {
            tmp2 = nums[i];
        }
        else {
            swap(tmp1, tmp2);
            if (tmp2)cnt++;
            tmp2 = nums[i];
        }
    }
    cout << cnt;
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