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
const int mod = 1e9 + 7;
// const int mod = 998244353;

void solve() {
    i64 t, n;std::cin >> t >> n;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    ranges::sort(a);
    i64 k, l;
    l = k = 1;
    i64 last = n;
    for (auto x : a) {
        i64 mul = t / last + (t % last != 0);
        if (x <= mul) t -= x;
        else t -= mul, k = k * mul % mod, l = l * x % mod;
        last--;
    }
    std::cout << k << ' ' << l << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}