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
    int a, b, c;std::cin >> a >> b >> c;
    if (a == 0 && b == 0 && c != 0) {
        std::cout << -1;
        return;
    }
    if (a == 0 && b == 0 && c == 0) {
        std::cout << 0;
        return;
    }
    std::vector<int> ans;
    auto work = [&](int x) {
        ans.push_back(x);
        switch (x)
        {
        case 1:
            a = a * 2;
            break;
        case 2:
            b = b / 2;
            break;
        case 3:
            a = a ^ b;
            break;
        case 4:
            b = b ^ a;
            break;
        }
        // std::cout << a << ' ' << b << ' ' << c << "\n";
        };
    if (std::__lg(a) > std::__lg(b)) work(4);
    while (std::__lg(b) > std::__lg(c)) {
        if (std::__lg(a) == std::__lg(b)) work(3);
        work(2);
    }
    for (int i = std::__lg(c);i > std::__lg(b);--i) {
        if ((a >> std::__lg(b) & 1) != (c >> i & 1)) {
            work(3);
        }
        work(1);
    }
    for (int i = std::__lg(b);i >= 0;--i) {
        if ((a >> i & 1) != (c >> i & 1)) {
            work(3);
        }
        work(2);
    }
    work(4);
    std::cout << ans.size() << '\n';
    for (int x : ans)std::cout << x << ' ';
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