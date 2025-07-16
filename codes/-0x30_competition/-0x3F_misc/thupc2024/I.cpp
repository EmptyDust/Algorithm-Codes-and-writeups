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

std::string str[16] = {
    "0000",
    "0001",
    "0010",
    "0100",
    "1000",
};

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    std::vector<a3> ans;
    auto add = [&](int a, int b, int c) {
        ans.push_back({ a,b,c });
        };
    add(1, 1, -1);
    for (int i = 2;i < (1 << 18);++i) {
        if (std::__popcount(i) == 1) add(3, 1, std::__lg(2));
        else add(2, i & -i, i - (i & -i));
    }

    std::cout << ans.size() << '\n';
    for (auto [x, y, z] : ans) {
        std::cout << x << " " << y << ' ';
        if (z != -1)std::cout << z << ' ';
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}