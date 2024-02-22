#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e3 + 10, mod = 1e9 + 7;
int nums[MAXN];
int dp[MAXN][MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 1;i <= n;++i)cin >> nums[i];
    bool cur = 1;
    for (int l = 1, r = n;l < r;) {
        if (cur) {

        }
        cur = !cur;
    }
    return 0;
}