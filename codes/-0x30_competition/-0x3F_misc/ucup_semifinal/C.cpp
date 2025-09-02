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
const i64 inf = 1e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

using i128 = __int128;

std::istream& operator>>(std::istream& is, i128& n) {
    std::string s;is >> s;
    n = 0;
    for (char i : s) n = n * 10 + i - '0';
    return is;
}
std::ostream& operator<<(std::ostream& os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    if (n < 0) os << '-', n = -n;
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

void solve() {
    int n;i128 k;std::cin >> n >> k;
    std::vector<i128> a(n);
    for (auto& x : a)std::cin >> x;
    i128 l = -2'000'000'000, r = 2'000'000'000 + 1;
    auto check_p = [&](auto y)->i128 {
        auto b(a);
        for (int i = 0;i < n - 1;++i) {
            i128 x = b[i] - y;
            if (x > inf) x = inf;
            if (x < -inf) x = -inf;
            b[i] -= x;
            b[i + 1] -= x * k;
        }
        return b[n - 1] - y;
        };

    if (check_p(l) <= check_p(r)) {
        auto check = [&](auto y)->bool {
            auto b(a);
            for (int i = 0;i < n - 1;++i) {
                i128 x = b[i] - y;
                if (x > inf) x = inf;
                if (x < -inf) x = -inf;
                b[i] -= x;
                b[i + 1] -= x * k;
            }
            return b[n - 1] - y >= 0;
            };
        while (l < r) {
            auto mid = l + r >> 1;
            if (check(mid))r = mid;
            else l = mid + 1;
        }
    }
    else {
        auto check = [&](auto y)->bool {
            auto b(a);
            for (int i = 0;i < n - 1;++i) {
                i128 x = b[i] - y;
                if (x > inf) x = inf;
                if (x < -inf) x = -inf;
                b[i] -= x;
                b[i + 1] -= x * k;
            }
            return b[n - 1] - y <= 0;
            };
        while (l < r) {
            auto mid = l + r >> 1;
            if (check(mid))r = mid;
            else l = mid + 1;
        }
    }
    std::cout << (check_p(l) == 0 ? "Yes" : "No");
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