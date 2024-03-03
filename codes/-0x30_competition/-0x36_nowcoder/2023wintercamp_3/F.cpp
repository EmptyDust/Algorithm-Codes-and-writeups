#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10, inf = 1e9;
int nums[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int ans = -inf;
    for (int i = 0;i < n;++i) {
        vector<int> bag(k + 1, -inf);
        for (int j = 0;j < n;++j) {
            int len = abs(i - j);
            for (int x = k;x >= len;x--) {
                bag[x] = max({ bag[x - len] + nums[j], bag[x],nums[j] });
                ans = max(ans, bag[x]);
            }
        }
    }
    cout << ans;
    return 0;
}