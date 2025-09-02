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


template<class T>
constexpr T power(T a, u64 b, T res = 1) {
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return u64(a) * b % P;
}

template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

constexpr i64 safeMod(i64 x, i64 m) {
    x %= m;
    if (x < 0) {
        x += m;
    }
    return x;
}

constexpr std::pair<i64, i64> invGcd(i64 a, i64 b) {
    a = safeMod(a, b);
    if (a == 0) {
        return { b, 0 };
    }

    i64 s = b, t = a;
    i64 m0 = 0, m1 = 1;

    while (t) {
        i64 u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        std::swap(s, t);
        std::swap(m0, m1);
    }

    if (m0 < 0) {
        m0 += b / s;
    }

    return { s, m0 };
}

template<std::unsigned_integral U, U P>
struct ModIntBase {
public:
    constexpr ModIntBase() : x(0) {}
    template<std::unsigned_integral T>
    constexpr ModIntBase(T x_) : x(x_% mod()) {}
    template<std::signed_integral T>
    constexpr ModIntBase(T x_) {
        using S = std::make_signed_t<U>;
        S v = x_ % S(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }

    constexpr static U mod() {
        return P;
    }

    constexpr U val() const {
        return x;
    }

    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }

    constexpr ModIntBase inv() const {
        return power(*this, mod() - 2);
    }

    constexpr ModIntBase& operator*=(const ModIntBase& rhs)& {
        x = mulMod<mod()>(x, rhs.val());
        return *this;
    }
    constexpr ModIntBase& operator+=(const ModIntBase& rhs)& {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr ModIntBase& operator-=(const ModIntBase& rhs)& {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
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

    friend constexpr std::istream& operator>>(std::istream& is, ModIntBase& a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const ModIntBase& a) {
        return os << a.val();
    }

    friend constexpr bool operator==(const ModIntBase& lhs, const ModIntBase& rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr std::strong_ordering operator<=>(const ModIntBase& lhs, const ModIntBase& rhs) {
        return lhs.val() <=> rhs.val();
    }

private:
    U x;
};

template<u32 P>
using ModInt = ModIntBase<u32, P>;
template<u64 P>
using ModInt64 = ModIntBase<u64, P>;

struct Barrett {
public:
    Barrett(u32 m_) : m(m_), im((u64)(-1) / m_ + 1) {}

    constexpr u32 mod() const {
        return m;
    }

    constexpr u32 mul(u32 a, u32 b) const {
        u64 z = a;
        z *= b;

        u64 x = u64((u128(z) * im) >> 64);

        u32 v = u32(z - x * m);
        if (m <= v) {
            v += m;
        }
        return v;
    }

private:
    u32 m;
    u64 im;
};

using Z = ModInt<mod>;

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() : n{ 0 }, _fac{ 1 }, _invfac{ 1 }, _inv{ 0 } {}
    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

constexpr int LIMIT = 8;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
    }

    std::vector<int> lim(n + 1);
    for (int i = 1; i <= n; i++) {
        lim[i] = std::__lg(i) + 1;
    }

    std::vector dp(n + 2, std::vector(n + 2, std::vector(LIMIT + 1, std::vector<Z>(LIMIT + 1, -1))));
    auto dfs = [&](auto&& dfs, int L, int R, int l, int r)->Z {
        if (l < 0 || r < 0) return 0;
        Z& ret = dp[L][R][l][r];
        if (ret != -1) return ret;
        ret = 0;
        if (L + 1 == R) {
            ret = (l == 0 || L == 0) && (r == 0 || R == n + 1);
            return ret;
        }
        for (int M = L + 1;M < R;++M) {
            Z mul = comb.binom(R - L - 2, M - L - 1);
            int liml = lim[M - L - 1];
            int limr = lim[R - M - 1];
            if (a[M] == -1) {
                Z lmul = 0, rmul = 0;
                for (int i = 0;i <= liml;++i) {
                    if (L == 0 && R == n + 1) {
                        lmul += dfs(dfs, L, M, l, i);
                    }
                    else if (R == n + 1 || std::abs(M - L) <= std::abs(M - R) && L != 0) {
                        lmul += dfs(dfs, L, M, l - 1, i);
                    }
                    else {
                        lmul += dfs(dfs, L, M, l, i);
                    }
                }
                for (int j = 0;j <= limr;++j) {
                    if (L == 0 && R == n + 1) {
                        rmul += dfs(dfs, M, R, j, r);
                    }
                    else if (R == n + 1 || std::abs(M - L) <= std::abs(M - R) && L != 0) {
                        rmul += dfs(dfs, M, R, j, r);
                    }
                    else {
                        rmul += dfs(dfs, M, R, j, r - 1);
                    }
                }
                ret += lmul * rmul * mul;
            }
            else {
                for (int i = 0;i <= std::min(a[M], liml);++i) if (a[M] - i <= limr) {
                    int j = a[M] - i;
                    if (L == 0 && R == n + 1) {
                        ret += dfs(dfs, L, M, l, i) * dfs(dfs, M, R, j, r) * mul;
                    }
                    else if (R == n + 1 || std::abs(M - L) <= std::abs(M - R) && L != 0) {
                        ret += dfs(dfs, L, M, l - 1, i) * dfs(dfs, M, R, j, r) * mul;
                    }
                    else {
                        ret += dfs(dfs, L, M, l, i) * dfs(dfs, M, R, j, r - 1) * mul;
                    }
                }
            }
        }
        return ret;
        };
    std::cout << dfs(dfs, 0, n + 1, LIMIT, LIMIT);
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