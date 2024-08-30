#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 n, m;std::cin >> n >> m;
    i64 res = 0;
    for (int i = 0;i < n;++i) {
        int k;std::cin >> k;
        std::vector<int> a(k);
        for (int& x : a)std::cin >> x;
        ranges::sort(a);
        i64 mex = 0;
        bool ok = true;
        for (int i = 0;i < k;++i) {
            if (a[i] > mex) {
                if (ok)mex++, ok = false;
                else break;
            }
            if (a[i] == mex)mex++;
        }
        mex += ok;
        res = std::max(res, mex);
    }
    if (m <= res) {
        i64 ans = (m + 1) * res;
        std::cout << ans;
        return;
    }
    // std::cout << res << ' ';
    i64 ans = (res + 1) * res + (res + 1 + m) * (m - res) / 2;
    std::cout << ans;
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