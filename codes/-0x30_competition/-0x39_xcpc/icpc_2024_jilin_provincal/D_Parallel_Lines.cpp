#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

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

#define x first
#define y second

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<pii> ps(n);
    for (auto& [x, y] : ps)std::cin >> x >> y;
    {
        bool f = true;
        std::map<int, std::vector<int>>mp;
        for (int i = 0;i < n;++i) {
            auto& [x, y] = ps[i];
            mp[x].push_back(i);
        }
        if (mp.size() != m)f = false;
        for (auto [x, vt] : mp)if (vt.size() == 1)
            f = false;
        if (f) {
            for (auto [x, vt] : mp) {
                std::cout << vt.size() << ' ';
                for (int p : vt)std::cout << p + 1 << " ";
                std::cout << '\n';
            }
            return 0;
        }
    }
    for (int i = 1;i < n;++i) {
        if (ps[i].x == ps[0].x)continue;
        F k(ps[i].y - ps[0].y, ps[i].x - ps[0].x);
        std::map<F, std::vector<int>> mp;
        bool f = true;
        // if (k == 0)std::cout << i << " ";
        for (int j = 0;j < n;++j) {
            F b = ps[j].second - k * ps[j].first;
            mp[b].push_back(j);
            if (mp.size() > m) {
                f = false;
                break;
            }
        }
        // if (k == 0)std::cout << '\n';
        if (mp.size() != m)f = false;
        for (auto [b, vt] : mp)if (vt.size() == 1)
            f = false;
        if (f) {
            for (auto [b, vt] : mp) {
                std::cout << vt.size() << ' ';
                for (int p : vt)std::cout << p + 1 << " ";
                std::cout << '\n';
            }
            return 0;
        }
    }
    std::cout << "Error";
    return 0;
}

