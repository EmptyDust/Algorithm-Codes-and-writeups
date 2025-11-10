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
    int n;std::cin >> n;
    std::string ans;
    for (int i = 0;i < n;++i) {
        int x; std::cin >> x;x--;
        ans += char(x + 'a');
    }
    std::cout << ans;
}

void decode() {
    std::string s;std::cin >> s;
    std::cout << s.length() << ' ';
    for (auto ch : s) {
        std::cout << int(ch - 'a') + 1 << ' ';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string type;std::cin >> type;
    if (type == "first") {
        encode();
    }
    else {
        decode();
    }
    return 0;
}