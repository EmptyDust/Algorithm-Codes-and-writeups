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
    std::string s;std::cin >> s;
    if (n == 2) {
        std::cout << (s[0] == 'A' ? "Alice" : "Bob");
        return;
    }
    if (s[n - 1] == 'B') {
        if (std::count(s.begin(), s.end(), 'B') == 1)std::cout << "Alice";
        else std::cout << "Bob";
        return;
    }
    if (s[n - 2] == 'A' || s[0] == 'A') {
        std::cout << "Alice";
        return;
    }
    std::cout << "Bob";
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