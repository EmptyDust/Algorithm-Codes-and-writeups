#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 n, k;std::cin >> n >> k;
    std::vector<a2> ans;
    i64 x = 1, cur = 0;
    for (int i = 2;i <= n;++i) {
        ans.push_back(a2{ x,i });
        i64 c = n - i;
        // std::cout << c << ' ';
        if (cur + c + c * (c - 1) / 2 > k + 1)continue;
        cur += c + c * (c - 1) / 2;
        x = i;
    }
    // std::cout << cur << ' ';
    if (std::abs(cur - k) <= 1) {
        std::cout << "Yes\n";
        for (auto [a, b] : ans)std::cout << a << ' ' << b << '\n';
    }
    else {
        std::cout << "No\n";
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