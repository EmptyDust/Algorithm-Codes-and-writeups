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
    i64 k;
    std::cin >> k;
    i64 l = 1, r = 1e9;
    auto check = [&](auto x)->bool {
        return x * (x + 1) >= k;
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    std::cout << k + l;
    // i64 k;//std::cin >> k;
    // for (int k = 1;k <= 100;++k) {
    //     for (int n = 1;n <= 1000;++n) {
    //         std::vector<int> a(n + 1, 1);
    //         for (int i = 1;i <= n;++i) {
    //             for (int j = i;j <= n;j += i) {
    //                 a[j] = !a[j];
    //             }
    //         }
    //         // if (n == 3)std::cout << std::count(a.begin(), a.end(), 1) << ' ';
    //         if (std::count(a.begin(), a.end(), 1) == k + 1) {
    //             std::cout << n - k << ' ';
    //             break;
    //         }
    //     }
    //     // std::cout << "?";
    // }
    /*
    1 1 2 2 2 2 3 3 3 3 3 3 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 7 7 7 7 7 7 7 7 7 7 7 7 7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 10 10 10 10 10 10 10 10 10 10
    */
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}