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
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    int p1 = ranges::find(a, 1) - a.begin() + 1;
    int p2 = ranges::find(a, n) - a.begin() + 1;
    std::string s;std::cin >> s;
    if (s.front() == '1' || s.back() == '1' || s[p1 - 1] == '1' || s[p2 - 1] == '1') {
        std::cout << -1 << '\n';
        return;
    }
    std::cout << 5 << '\n';
    std::cout << 1 << ' ' << p1 << '\n';
    std::cout << 1 << ' ' << p2 << '\n';
    std::cout << p1 << ' ' << n << '\n';
    std::cout << p2 << ' ' << n << '\n';
    std::cout << std::min(p1, p2) << ' ' << std::max(p1, p2) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}