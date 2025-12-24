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
    i64 n, k;std::cin >> n >> k;
    int max = 0;
    for (int a = 0;a <= n;++a) {

        for (int b = 0;b <= n;++b) {

            for (int c = 0;c <= n;++c) {

                for (int d = 0;d <= n;++d) {
                    if ((a ^ b ^ c ^ d) == n) {
                        // if (a + b + c + d == 278) {
                        //     // std::cout << a << ' ' << b << " " << c << " " << d << "\n";
                        //     std::cout << std::bitset<10>(86) << '\n';
                        //     std::cout << std::bitset<10>(a) << '\n' <<
                        //         std::bitset<10>(b) << '\n'
                        //         << std::bitset<10>(c) << "\n"
                        //         << std::bitset<10>(d) << "\n";
                        // }
                        max = std::max(max, a + b + c + d);
                    }
                }
            }
        }
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

/*
31 79 83 85
31 79 85 83
31 83 79 85
31 83 85 79
31 85 79 83
31 85 83 79
79 31 83 85
79 31 85 83
79 83 31 85
79 83 85 31
79 85 31 83
79 85 83 31
83 31 79 85
83 31 85 79
83 79 31 85
83 79 85 31
83 85 31 79
83 85 79 31
85 31 79 83
85 31 83 79
85 79 31 83
85 79 83 31
85 83 31 79
85 83 79 31
278

*/