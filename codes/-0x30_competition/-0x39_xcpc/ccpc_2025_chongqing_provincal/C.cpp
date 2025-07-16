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

/*
1 2 3 4 5 6 7
6 7 1 2 3 4 5


*/

void solve() {
    int n;std::cin >> n;
    int t = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            std::cout << (j - t + n) % n + 1 << " \n"[j == n - 1];
        }
        t = (t + i + 2) % n;
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