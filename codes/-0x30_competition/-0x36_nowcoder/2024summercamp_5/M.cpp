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
        T g = std::__gcd(den, num);
        num /= g;
        den /= g;
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
        // if (x.den == g) {
        //     return os << x.num / g;
        // }
        // else {
        return os << x.num / g << "/" << x.den / g;
        // }
    }
};

void solve() {
    i64 c, a, b;std::cin >> c >> a >> b;
    Frac<i64> p = Frac<i64>(a, b);
    std::vector fs(c + 1, std::vector<Frac<i64>>(c + 1, Frac<i64>()));
    //全部询问左侧 <x,y> p x次为真 y次为假 P<x,y> = p
    for (i64 i = 0;i <= c;++i) {
        for (i64 j = 0;j <= c;++j) {
            i64 k = i + j;
            if (k > c)break;
            if (k == 0) {
                fs[i][j] = Frac<i64>(1, 2) * c;
                continue;
            }
            auto P = Frac(i, k) * p + Frac(j, k) * (1 - p);
            fs[i][j] = std::max(P, 1 - P) * (c - i - j) + std::min(P, 1 - P) * (-i - j);
            // if (i == 0 && j == 1)std::cout << P << '\n';
        }
    }
    // std::cout << Frac<i64>(1, 1) * p * (c - 1) << "\n";

    // auto  get = [&](int i, int j)->Frac<i64> {
    //     if (i < j)std::swap(i, j);
    //     return fs[i][j];
    //     };
    // std::cout << (fs[0][0] < Frac<i64>(33773, 7768)) << ' ';

    // std::cout << (fs[0][0] < fs[i + 1][j] * p + fs[i][j + 1] * (1 - p));

    for (int i = c - 1;i >= 0;--i) {
        for (int j = c - 1;j >= 0;--j) {
            int k = i + j;
            if (k >= c)continue;
            if (i == 0 && j == 0)
                std::cout << fs[i][j] << ' ';
            if (i == 0 && j == 0)
                std::cout << (fs[0][0] < fs[i + 1][j] * p + fs[i][j + 1] * (1 - p)) << ' ';
            if (i == 0 && j == 0)
                std::cout << fs[i + 1][j] * p + fs[i][j + 1] * (1 - p) << "\n";
            if ((fs[i][j] < (fs[i + 1][j] * p + fs[i][j + 1] * (1 - p)))) {
                if (i == 0 && j == 0)std::cout << fs[0][0] << " ";
                fs[i][j] = fs[i + 1][j] * p + fs[i][j + 1] * (1 - p);
            }
            if (i == 0 && j == 0)
                std::cout << fs[i][j] << '\n';
        }
    }

    std::cout << fs[0][0];

    // std::queue<std::tuple<int, int, Frac<i64>>> q;
    // q.push({ 0,0,1 });
    // Frac<i64> ans = 0;
    // while (q.size()) {
    //     auto [x, y, F] = q.front();
    //     q.pop();
    //     auto P = fs[x][y];
    //     auto nP = p * fs[x + 1][y] + (1 - p) * fs[x][y + 1];
    //     if (nP > P)q.push({ x + 1,y,F * p }), q.push({ x,y + 1,F * (1 - p) });
    //     else {
    //         std::cout << x << ' ' << y << '\n';
    //         std::cout << P << ' ';
    //         std::cout << nP << '\n';
    //         ans += F * P;
    //     }
    // }
    // std::cout << ans;
}
//一个物品可能是真的也可能是假的 。现在有一个人有p概率说真话，询问k次物品是否为真，其中a次回答是真的， 物品是真的的概率是多少
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