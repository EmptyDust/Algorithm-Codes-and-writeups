#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    auto l = 1, r = n + 1;
    auto check = [&](auto x)->bool {
        int cnt = 0, mex = 0;
        std::vector<int> tmp(x);
        for (int i = 0;i < n;++i) {
            if (a[i] < x)tmp[a[i]] = 1;
            while (mex < x && tmp[mex])mex++;
            if (mex == x) {
                cnt++;
                mex = 0;
                tmp.assign(x, 0);
            }
        }
        // std::cout << cnt << '\n';
        return cnt < k;
        };
    // std::cout << check(5) << " ";
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    std::cout << l - 1;
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