#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
#define r(x) (x>>1)
constexpr int MAXN = 1e6;
int nums[MAXN], ans[MAXN];

int solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int t = 1, res = 0, up = ceil(log2(n));
    ans[0] = nums[0];
    for (int i = 0;i <= up;++i) {
        res ^= nums[i];
        if (i == t)ans[i] = res, t <<= 1;
    }
    t = up;
    for (int i = up;i >= 0;--i) {
        if (i == t) {
            t >>= 1;
            continue;
        }
        int tmp = 1, num = i;
        while (num & 1)num >>= 1, tmp <<= 1;
        tmp += num;
        ans[i] = ans[tmp] ^ nums[tmp];
    }
    ull ret = 0;
    for (int i = 0;i < n;++i)
        ret += (i + 1) * ans[i];
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--)cout << solve() << '\n';
    return 0;
}