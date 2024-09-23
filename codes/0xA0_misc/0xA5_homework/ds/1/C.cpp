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

template<class T>
class Complex {
    T a, b;
public:
    Complex() :a(0), b(0) {}
    Complex(T x, T y) :a(x), b(y) {}
    Complex operator+ (Complex& x) {
        return Complex(a + x.a, b + x.b);
    }
    Complex operator- (Complex& x) {
        return Complex(a - x.a, b - x.b);
    }
    std::string tostring() {
        auto x = std::to_string(a);
        if (b > 0)x += '+' + std::to_string(b) + "i";
        else if (b < 0)x += std::to_string(b) + "i";
        return x;
    }
    friend std::ostream& operator<<(std::ostream& output,
        const Complex& c)
    {
        auto x = std::to_string(c.a);
        if (c.b > 0)x += '+' + std::to_string(c.b) + "i";
        else if (c.b < 0)x += std::to_string(c.b) + "i";
        output << x << "\n";
        return output;
    }
    friend std::istream& operator>>(std::istream& input, Complex& c)
    {
        input >> c.a >> c.b;
        return input;
    }
};

void solve() {
    Complex<double> a, b;
    std::cin >> a >> b;
    std::cout << a + b;
    std::cout << a - b;
    std::cout << a.tostring();
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
