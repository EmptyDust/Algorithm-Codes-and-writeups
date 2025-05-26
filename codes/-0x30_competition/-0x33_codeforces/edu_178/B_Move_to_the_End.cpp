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
    std::vector<i64> a(n), prem(n), sufs(n + 1);
    for (auto& x : a)std::cin >> x;
    prem[0] = a[0];
    for (int i = 1;i < n;++i)prem[i] = std::max(prem[i - 1], a[i]);
    for (int i = n - 1;i >= 0;--i)sufs[i] = sufs[i + 1] + a[i];
    for (int k = 0;k < n;++k) {
        std::cout << sufs[n - k] + prem[n - 1 - k] << ' ';
    }
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