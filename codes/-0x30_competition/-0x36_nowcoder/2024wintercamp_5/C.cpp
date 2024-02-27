#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e5 + 10, mod = 1e9 + 7;
using pt = pair<int, int>;
int nums[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 1;i <= n;++i)cin >> nums[i], nums[i]--;
    nums[0] = nums[n + 1] = 1e9;
    int ans = 0;
    for (int i = 1;i <= n + 1;++i) {
        int cnt = min(nums[i], nums[i - 1]);
        ans += cnt;
        nums[i] -= cnt;
    }
    cout << ans;
    return 0;
}