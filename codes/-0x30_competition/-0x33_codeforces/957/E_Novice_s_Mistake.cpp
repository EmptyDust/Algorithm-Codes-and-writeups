#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

// pii cal(i64 a1, i64 b1, i64 c1, i64 a2, i64 b2, i64 c2) {
//     //a1x+b1y = c1
//     //a2x+b2y = c2
//     a1 *= a2, b1 *= a2, c1 *= a2;
//     a2 *= a1, b2 *= a1, c2 *= a1;
//     i64 c = c1 - c2, b = b1 - b2;
//     if (c % b)return { -1,-1 };
//     i64 y = c / b;
//     if ((c2 - b2 * y) % a2)return { -1,-1 };
//     i64 x = (c2 - b2 * y) / a2;
//     if (x <= 0 || y <= 0)return { -1,-1 };
//     i64 g = std::__gcd(x, y);
//     return { x / g,y / g };
// }
void solve() {
    // 3*a-b = 2   10 = a*n-b
    // res - |res| = (n - |n|) * a
    //  res  =  n  * a - b
    // |res| = |n| * a - b
    int n;std::cin >> n;
    if (n == 1) {
        std::vector<pii> ans;
        for (int a = 1;a <= 10000;++a) {
            int b = a - 1;
            if (0 < a && a <= 10000 && 0 < b && b <= std::min(10000, a * n)) {
                ans.push_back({ a,b });
            }
        }
        std::cout << ans.size() << '\n';
        for (auto& [a, b] : ans) {
            std::cout << a << ' ' << b << '\n';
        }
        return;
    }
    int len_n = -1;
    std::string s;
    {
        int _n = n;
        while (_n) {
            s.push_back('0' + (_n % 10));
            _n /= 10;
        }
        std::reverse(s.begin(), s.end());
        len_n = s.length();
        s = s + s + s + s + s + s + s + s;
    }
    std::vector<pii> ans;
    for (int i = 1;i <= 6;++i) {
        int res = std::stoi(s.substr(0, i));
        int l = res - i;
        int _n = n - len_n;
        // std::cout << _n << '\n';
        if (_n == 0 || l % _n)continue;
        int a = l / _n;
        int b = a * n - res;
        if (0 < a && a <= 10000 && 0 < b && b <= std::min(10000, a * n)) {
            ans.push_back({ a,b });
        }
    }
    std::cout << ans.size() << '\n';
    for (auto& [a, b] : ans) {
        std::cout << a << ' ' << b << '\n';
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