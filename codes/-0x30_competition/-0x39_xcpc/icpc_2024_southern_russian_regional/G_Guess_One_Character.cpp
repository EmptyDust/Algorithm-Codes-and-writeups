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

// 01 10 
// ==
// 010
// 
// 10101
// 01010

// 1001101
// 0110010

// 0 01

// 1 11 01

int ask(const std::string& s) {
    std::cout << "1 " << s << std::endl;
    int x;std::cin >> x;
    return x;
}

// __attribute__((target("popcnt")))
void solve() {
    int n;std::cin >> n;
    int x = ask("1");
    int y = ask("11");
    int z = ask("01");
    if (z == x - y) {
        std::cout << "0 1 0" << std::endl;
    }
    else {
        std::cout << "0 1 1" << std::endl;
    }
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