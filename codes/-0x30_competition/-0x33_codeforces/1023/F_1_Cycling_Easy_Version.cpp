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
    int n;std::cin >> n;
    std::vector<i64> a(n), dp(n);
    for (auto& x : a)std::cin >> x;
    std::vector<int> stk;
    for (int i = 0;i < n;++i) {
        while (stk.size() && a[stk.back()] > a[i])stk.pop_back();
        stk.push_back(i);
    }
    std::vector<int> use(1, stk[0]);
    for (int i = 1;i < stk.size();++i) {
        for (int j = 0;j < use.size();++j) {
            if ((stk[i] - use[j]) * (a[stk[i]] - a[use[j]])) {

            }

        }
    }
    // i64 ans = 0;
    // int minp = std::min_element(a.begin(), a.end()) - a.begin();
    // auto work = [&](int p) {
    //     int pre = 0;
    //     for (int i = p;i >= 0;--i)if (a[i] == a[minp]) {
    //         pre = i;
    //         break;
    //     }
    //     std::swap(a[pre], a[p]);
    //     i64 res = p - pre;
    //     for (int i = p;i >= 0;--i) {
    //         if (a[i] == a[p])res += a[p];
    //         else res += a[p] + 1;
    //     }
    //     std::swap(a[pre], a[p]);
    //     return res;
    //     };
    // i64 psum = 0, ans = 0;
    // for (int i = n - 1;i >= minp;--i) {
    //     ans = std::min(ans, psum + work(i));
    //     psum += a[i];
    // }
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