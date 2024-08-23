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
    std::string s;std::cin >> s;
    int i = 0;
    while (i < s.length()) {
        if (i + 5 <= s.length() && s.substr(i, 5) == "avava") {
            i += 5;
        }
        else if (i + 3 <= s.length() && s.substr(i, 3) == "ava") {
            i += 3;
        }
        else {
            std::cout << "No";
            return;
        }
    }
    std::cout << "Yes";
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