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
    int n;std::cin >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    ranges::sort(a);
    i64 min = a[0];
    i64 gcd = 0;
    for (int i = 1;i < n;++i) {
        if (a[i] % min == 0)gcd = std::gcd(gcd, a[i]);
    }
    if (gcd == min) { std::cout << "Yes"; }
    else std::cout << "No";
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