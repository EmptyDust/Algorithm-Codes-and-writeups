#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

i64 m;

void exGCD(i64 a, i64 b, i64& x, i64& y) {
    if (!b) x = 1, y = 0;
    else exGCD(b, a % b, y, x), y = (y - a / b * x % m + m) % m;
}

void solve() {
    i64 n;std::cin >> n >> m;
    i64 a = n % m, b = n * (n + 1) / 2 % m;
    i64 sum = 0;
    for (int i = 0;i < n;++i) {
        int tmp;std::cin >> tmp;
        sum = (sum + tmp) % m;
    }
    if (!a && !b) {
        std::cout << sum << '\n';
        std::cout << 0 << ' ' << 0 << '\n';
        return;
    }
    i64 cc = std::gcd(a, b), c = std::gcd(cc, m);
    i64 ans = sum % c;sum -= ans;
    i64 s, d, x, k;
    a /= cc, b /= cc;(b > a) ? exGCD(b, a, d, s) : exGCD(a, b, s, d);
    sum /= c, cc /= c, m /= c;(cc > m) ? exGCD(cc, m, x, k) : exGCD(m, cc, k, x);
    //x %= m, s = (s % m + m) % m, d = (d % m + m) % m;
    // std::cout << s << ' ' << d << '\n';
    i64 mul = x * (m - sum) % m;
    std::cout << ans << '\n';
    std::cout << s * mul % m << ' ' << d * mul % m << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}