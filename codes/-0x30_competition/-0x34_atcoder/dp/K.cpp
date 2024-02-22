#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e5 + 10, mod = 1e9 + 7;
int nums[MAXN];
bool dp[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n, k;cin >> n >> k;
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int i = 0;i <= k;++i) {
        bool& cur = dp[i] = false;
        for (int j = 0;j < n;++j) {
            if (i - nums[j] >= 0 && !dp[i - nums[j]]) {
                dp[i] = true;
                break;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second");
    return 0;
}