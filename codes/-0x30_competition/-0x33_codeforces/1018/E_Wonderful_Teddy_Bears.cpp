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
    std::vector<int> vis(n);
    int lo = n - 1, le = n - 1;
    if (n % 2)lo--;
    else le--;
    // std::cout << lo << ' ' << le << '\n';
    i64 ans = 0;
    for (int i = n - 1;i >= 0;--i) {
        if (s[i] == 'P') {
            if (i % 2) {
                ans += (lo - i) / 2;
                lo -= 2;
            }
            else {
                ans += (le - i) / 2;
                le -= 2;
            }
        }
    }
    while (std::abs(lo - le) > 1) {
        if (lo < le) {
            lo += 2;
            ans++;
            ans += (le - lo) / 2;
            le -= 2;
        }
        else {
            le += 2;
            ans++;
            ans += (lo - le) / 2;
            lo -= 2;
        }
    }
    std::cout << ans;
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