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
    i64 n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    if (n == 1) {
        if (a[0] < k)std::cout << k;
        else std::cout << k - 1;
        return;
    }
    int gcd = a[0];
    for (int x : a)gcd = std::__gcd(gcd, x);
    i64 l = 0, r = 2e9;
    auto check = [&](auto x)->bool {
        return x + 1 - std::min(n, x / gcd + 1) >= k;
        };
    // std::cout << gcd;
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    std::cout << l;
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