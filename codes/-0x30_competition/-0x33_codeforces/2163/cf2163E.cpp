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

void encode() {
    int n, C;std::cin >> n >> C;
    std::vector map1(n, std::vector<int>(n)), map2(n, std::vector<int>(n));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < n;++j) {
            map1[i][j] = s[j] - '0';
            map2[j][i] = s[j] - '0';
        }
    }
    if (C) {
        int x = ranges::max_element(map1) - map1.begin();
        int y = ranges::min_element(map2) - map2.begin();
        std::cout << x + 1 << ' ' << y + 1 << '\n';
    }
    else {
        int x = ranges::min_element(map1) - map1.begin();
        int y = ranges::max_element(map2) - map2.begin();
        std::cout << x + 1 << ' ' << y + 1 << '\n';
    }
}

void decode() {
    int n;std::cin >> n;
    std::string a, b;std::cin >> a >> b;
    std::cout << (a >= b ? 1 : 0) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string type;std::cin >> type;
    int t = 1;
    std::cin >> t;
    while (t--) {
        if (type == "first") {
            encode();
        }
        else {
            decode();
        }
    }
    return 0;
}