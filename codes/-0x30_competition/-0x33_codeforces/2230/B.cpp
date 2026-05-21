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
    int n;
    std::string s;
    std::cin >> s;
    n = s.size();
    std::string t;
    int ans = 0, T = 0;
    for (char ch : s) {
        int x = ch - '0';
        if (x % 4 == 0) {
            ans++;
        } else if (x % 2) {
            T--;
        } else if (x == 2 || x == 6) {
            T++;
            if (T <= 0)
                ans++;
            else 
                T--;
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}