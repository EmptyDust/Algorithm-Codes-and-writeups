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
struct ModIntBase {
public:
    constexpr ModIntBase() : x{ 0 } {}

    template<typename T>
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

//a + b + c + d = n - 9
void solve() {
    int n;std::cin >> n;
    std::vector dp(n + 1, std::vector<Z>(10));
    dp[0][0] = 1;
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j < 10;++j)
            dp[i][j] += dp[i - 1][j - 1];
        dp[i][0] += dp[i - 1][0] * 25;
        dp[i][0] += dp[i - 1][1] * 24;
        dp[i][1] += dp[i - 1][1];
        dp[i][0] += dp[i - 1][2] * 25;

        dp[i][3] += dp[i - 1][3] * 25;
        dp[i][3] += dp[i - 1][4] * 24;
        dp[i][4] += dp[i - 1][4];
        dp[i][3] += dp[i - 1][5] * 25;

        dp[i][6] += dp[i - 1][6] * 25;
        dp[i][6] += dp[i - 1][7] * 24;
        dp[i][7] += dp[i - 1][7];
        dp[i][6] += dp[i - 1][8] * 25;

        dp[i][9] += dp[i - 1][9] * 26;
    }
    std::cout << dp[n][9];
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