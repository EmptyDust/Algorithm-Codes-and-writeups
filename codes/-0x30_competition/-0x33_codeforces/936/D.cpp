#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN];
using pt = std::pair<int, int>;

void solve() {
    int n, x;std::cin >> n >> x;x++;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    for (int i = 1;i < n;++i) nums[i] ^= nums[i - 1];
    int msk = 0, res = -1;
    for (int s = 30;s >= 0;--s)if (x >> s & 1) {
        msk |= 1 << s;
        int cnt = 0;
        for (int i = 0;i < n;++i) {
            if ((nums[i] & msk) == 0) {
                cnt++;
            }
        }
        if ((msk & nums[n - 1]) == 0)
            res = std::max(res, cnt);
        msk ^= 1 << s;
    }
    else msk |= 1 << s;
    std::cout << res;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}