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

using i128 = __int128;

std::istream& operator>>(std::istream& is, i128& n) {
    std::string s;is >> s;
    n = 0;
    for (char i : s) n = n * 10 + i - '0';
    return is;
}
std::ostream& operator<<(std::ostream& os, i128 n) {
    if (n < 0) os << '-', n = -n;
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

void solve() {
    i64 _x;std::cin >> _x;
    i128 x = _x;
    i128 max = -(i128)1e18 * (i128)1e18;
    // std::cout << max << '\n';
    std::vector<int> vt;
    int f = 1;
    if (x < 0) f = -1, x = -x;
    else if (x == 0) vt.push_back(0);
    while (x) {
        vt.push_back(x % 10);
        x /= 10;
    }
    for (int p = 0;p <= vt.size();++p) {
        i128 res = 0;
        for (int r = vt.size() - 1;r >= p;--r) {
            res = res * 10 + vt[r];
        }
        res = res * 10 + 1;
        for (int l = p - 1;l >= 0;--l) {
            res = res * 10 + vt[l];
        }
        max = std::max(max, res * f);
    }
    std::cout << max;
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