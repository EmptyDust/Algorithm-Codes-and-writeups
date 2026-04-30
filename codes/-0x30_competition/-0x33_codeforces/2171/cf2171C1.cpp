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
    std::vector<int> a(n), b(n);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    for (int t = 28;t >= 0;--t) {
        int cnt = 0;
        for (auto x : a) if (x >> t & 1) cnt++;
        for (auto x : b) if (x >> t & 1) cnt++;
        if (cnt % 2) {
            for (auto& x : a) x = x >> t & 1;
            for (auto& x : b) x = x >> t & 1;
            for (int i = n - 1;i >= 0; --i) if (a[i] != b[i]) {
                std::cout << (i % 2 ? "Mai" : "Ajisai");
                return;
            }
            break;
        }
    }
    std::cout << "Tie";
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