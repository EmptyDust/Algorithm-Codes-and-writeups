#include <bits/stdc++.h>

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
    int a, b, c;std::cin >> a >> b >> c;
    if (a % 2 == b % 2 && b % 2 == c % 2) {
        int mask = a & b & c;
        mask = mask & -mask;//lowbit
        mask = mask << 1;
        a %= mask, b %= mask, c %= mask;
        if (a == b && b == c) {
            std::cout << "NO";
        }
        else std::cout << "YES";
    }
    else std::cout << "YES";
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