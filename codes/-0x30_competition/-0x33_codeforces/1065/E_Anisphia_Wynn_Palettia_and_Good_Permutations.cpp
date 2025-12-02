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
1 2 3 4 5 6 7 8 9 10 11 12 13 14
+ - + - + - + - + -  + -

1 2 4 7 6 3 11 9 12 5 8 10
- - - - - - -  - -  - -

1 2 4 7 6 3 11 9 12 5 8 10 13 14 16 19 18 15 23 21 24 17 20 22 25 26 27 28 29 30
- - - - - - -  - -  - - -  -  -  -  -  -  -  -  -  -  -  -  -  +  -  +  -
*/

int model[12] = { 1, 2, 4, 7, 6, 3, 11, 9, 12, 5, 8, 10 };

void solve() {
    int n;std::cin >> n;
    for (int i = 0; i < n;i += 12) {
        if (i + 12 <= n) {
            for (int j = 0;j < 12;++j) {
                std::cout << i + model[j] << ' ';
            }
        }
        else {
            for (int j = i + 1;j <= n;++j) {
                std::cout << j << ' ';
            }
        }
    }
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