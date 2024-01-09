#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6, mod = 998244353;
int nums[MAXN], f[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i], f[i] = 1;
    for (int i = n - 1;i >= 0;--i) {
        for (int j = 1;i + nums[i] * j < n;++j) {
            if (nums[i] == nums[i + nums[i] * j]) {
                f[i] += 2 * f[i + nums[i] * j] - 1;
                f[i] %= mod;
                break;
            }
            f[i] += f[i + nums[i] * j];
            f[i] %= mod;
        }
    }
    cout << f[0];
    return 0;
}