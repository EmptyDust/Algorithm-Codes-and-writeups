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
    int n = s.length();
    if (std::count(s.begin(), s.end(), '1') == n) {
        std::cout << "1 " << n << ' ' << "1 1";
        return;
    }
    int p = 0;
    while (s[p] != '0')p++;
    int cnt1 = p;
    int cnt0 = 0;
    while (p < n && s[p] != '1')cnt0++, p++;
    // std::cout << p << ' ';
    if (cnt0 >= cnt1)
        std::cout << 1 << ' ' << n << ' ' << 1 << ' ' << n - cnt1;
    else
        std::cout << 1 << ' ' << n << ' ' << cnt1 + 1 - cnt0 << ' ' << cnt1 + 1 - cnt0 + n - cnt1 - 1;
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