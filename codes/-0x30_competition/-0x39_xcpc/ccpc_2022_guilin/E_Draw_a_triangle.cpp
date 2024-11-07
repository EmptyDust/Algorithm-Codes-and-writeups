#include<bits/stdc++.h>

using i64 = long long;

using i128 = __int128;

std::istream& operator>>(std::istream& is, i128& n) {
    std::string s;is >> s;
    bool sgn = 1;
    if (s[0] == '-'){
        s = s.substr(1);
        // std::cout << s << ' ';
        sgn = 0;
    }
    n = 0;
    for (char i : s) n = n * 10 + i - '0';
    if (!sgn)n = -n;
    return is;
}
std::ostream& operator<<(std::ostream& os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    if (n < 0){
        os << '-';
        n = -n;
    }
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

void exGCD(i128 a, i128 b, i128& x, i128& y) {
    if (!b) x = 1, y = 0;
    else exGCD(b, a % b, y, x), y -= a / b * x;
}

void cal(i128 x1, i128 y1, i128 x2, i128 y2, i128 x3, i128 y3){
    // std::cout << x1 << ' ' << y2 << '\n';
    std::cout << x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2 << '\n';
}

void solve(){
    i128 x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    // |x1y2-x2y1+(x2-x1)y3+(y1-y2)x3|=0
    // A*x3+B*y3 = C
    // if (y1 < y2)std::swap(y1, y2), std::swap(x1, x2);
    i128 A = y1 - y2;
    i128 B = x2 - x1;
    // std::cout << y1 << ' ' << y2 << ' ' << B << '\n';

    if (B && A % B == 0){
        std::cout << x1 << ' ' << y1 + 1 << '\n';
        return;
    }
    if (A && B % A == 0){
        std::cout << x1 + 1 << " " << y1 << '\n';
        return;
    }
    i128 x3, y3;
    exGCD(A, B, x3, y3);
    x3 += x1, y3 += y1;
    std::cout << x3 << ' ' << y3 << '\n';
    // i128 C = x2 * y1 - x1 * y2;
    // i128 g = std::__gcd(A, B);

    // i128 low;

    // if (g - C % g > C % g)
    //     C -= C % g;
    // else
    //     C += g - C % g;
    // i128 mul = C / g;
    // x3 *= mul, y3 *= mul;
    // std::cout << (i128)-12421324 << '\n';
    // cal(x1, y1, x2, y2, x3, y3);
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    // cal(0, 1, 0, 9, 1, 1);
    int t = 1;std::cin >> t;
    while (t--){
        solve();
    }
    return 0;
}