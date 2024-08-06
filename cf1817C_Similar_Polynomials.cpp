#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;
// const int mod = 998244353;

template<typename T>
constexpr T power(T a, u64 b) {
    T res{ 1 };
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}

template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return 1ULL * a * b % P;
}

template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

template<typename U, U P>
    requires std::unsigned_integral<U>
struct ModIntBase {
public:
    constexpr ModIntBase() : x{ 0 } {}

    template<typename T>
        requires std::integral<T>
    constexpr ModIntBase(T x_) : x{ norm(x_ % T {P}) } {}

    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }

    constexpr U val() const {
        return x;
    }

    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }

    constexpr ModIntBase inv() const {
        return power(*this, P - 2);
    }

    constexpr ModIntBase& operator*=(const ModIntBase& rhs)& {
        x = mulMod<P>(x, rhs.val());
        return *this;
    }

    constexpr ModIntBase& operator+=(const ModIntBase& rhs)& {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr ModIntBase& operator-=(const ModIntBase& rhs)& {
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr ModIntBase& operator/=(const ModIntBase& rhs)& {
        return *this *= rhs.inv();
    }

    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase& rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase& rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase& rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const ModIntBase& a) {
        return os << a.val();
    }

    friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() < rhs.val();
    }

private:
    U x;
};

template<u32 P>
using ModInt = ModIntBase<u32, P>;

template<u64 P>
using ModInt64 = ModIntBase<u64, P>;

constexpr u32 P = mod;
using Z = ModInt<P>;

std::vector<Z> fact(1, 1);
std::vector<Z> inv_fact(1, 1);
Z comb(int n, int k) {
    if (k<0 || k>n)return 0;
    while ((Z)fact.size() < n + 1) {
        fact.push_back(1ll * fact.back() * (Z)fact.size());
        inv_fact.push_back(fact.back().inv());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}

Z getp(std::vector<int> nums, int p, int d) {
    Z res = 0;
    for (int i = p;i < p + d;++i) {
        res += ((i - p) % 2 ? -1 : 1) * comb(d - 1, i - p) * nums[i];
        // std::cout << nums[i] << ' ';
    }
    return res;
}

void solve() {
    int d;std::cin >> d;
    std::vector<int> a(d + 1), b(d + 1);
    for (int i = 0;i <= d;++i)std::cin >> a[i];
    for (int i = 0;i <= d;++i)std::cin >> b[i];
    auto a0 = getp(a, 0, d), a1 = getp(a, 1, d);
    auto b0 = getp(b, 0, d), b1 = getp(b, 1, d);
    // std::cout << a0 << ' ' << a1 << '\n';
    // std::cout << b0 << ' ' << b1 << '\n';
    //a1 = k + b
    //a0 = b
    //a1 - a0 = k

    // b0 = (a1 - a0) * s + a0
    // b1 = (a1 - a0) * (s + 1) + a0
    // b1 = (a1 - a0) * s + a1
    Z s1 = (b0 - a0) * (a1 - a0).inv();
    Z s2 = (b1 - a1) * (a1 - a0).inv();
    // std::cout << (b0 - a0) << ' ';
    std::cout << s1;// << ' ' << s2;
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