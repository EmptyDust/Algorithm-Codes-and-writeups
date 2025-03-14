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
    int k, m, s;std::cin >> k >> m >> s;
    std::cout << std::bitset<20>(s) << '\n';
    int cnt = 0, cnt2 = 0;
    // std::cout << (1 << k) << ' ';
    for (int i = 0;i < (1 << k);++i) {
        int sum = i + (s ^ i);
        if (std::__popcount(sum) == m) {
            cnt++;
            if (sum < (1 << m))cnt2++;
            // std::cout << sum << ' ' << (1 << m) << '\n';
            // std::cout << i << ' ' << (s ^ i) << '\n';
        }
    }
    std::cout << cnt / 2 << ' ' << cnt2 / 2;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}