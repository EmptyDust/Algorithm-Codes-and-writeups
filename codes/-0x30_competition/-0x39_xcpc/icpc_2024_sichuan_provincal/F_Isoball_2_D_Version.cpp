#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 N = 1e6, MAXN = 1e6 + 10, inf = 1e18, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;

template<class T>
struct Frac {
    T num;
    T den;
    Frac(T num_, T den_) : num(num_), den(den_) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num_) : Frac(num_, 1) {}
    explicit operator double() const {
        return 1. * num / den;
    }
    Frac& operator+=(const Frac& rhs) {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac& operator-=(const Frac& rhs) {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac& operator*=(const Frac& rhs) {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    Frac& operator/=(const Frac& rhs) {
        num *= rhs.den;
        den *= rhs.num;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac& rhs) {
        return lhs += rhs;
    }
    friend Frac operator-(Frac lhs, const Frac& rhs) {
        return lhs -= rhs;
    }
    friend Frac operator*(Frac lhs, const Frac& rhs) {
        return lhs *= rhs;
    }
    friend Frac operator/(Frac lhs, const Frac& rhs) {
        return lhs /= rhs;
    }
    friend Frac operator-(const Frac& a) {
        return Frac(-a.num, a.den);
    }
    friend bool operator==(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
    friend bool operator!=(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den != rhs.num * lhs.den;
    }
    friend bool operator<(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    friend bool operator>(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    friend bool operator<=(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    friend bool operator>=(const Frac& lhs, const Frac& rhs) {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }
    friend std::ostream& operator<<(std::ostream& os, Frac x) {
        T g = std::gcd(x.num, x.den);
        if (x.den == g) {
            return os << x.num / g;
        }
        else {
            return os << x.num / g << "/" << x.den / g;
        }
    }
};

using F = Frac<i64>;

void solve() {
    i64 x, y, r, vx, vy;
    std::cin >> x >> y >> r >> vx >> vy;
    i64 lx, ly, rx, ry;
    std::cin >> lx >> ly >> rx >> ry;

    F t = 0;
    if (vx > 0) {
        t = std::max(t, F(lx + r - x, vx));
    }
    else if (vx < 0) {
        t = std::max(t, F(rx - r - x, vx));
    }
    if (vy > 0) {
        t = std::max(t, F(ly + r - y, vy));
    }
    else if (vy < 0) {
        t = std::max(t, F(ry - r - y, vy));
    }
    if (x + t * vx - r >= lx && x + t * vx + r <= rx && y + t * vy - r >= ly && y + t * vy + r <= ry) {
        std::cout << "Yes";
    }
    else std::cout << "No";
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
