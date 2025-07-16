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
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<i64 P>
struct MLong {
    i64 x;
    constexpr MLong() : x{} {}
    constexpr MLong(i64 x) : x{ norm(x % getMod()) } {}

    static i64 Mod;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        }
        else {
            return Mod;
        }
    }
    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }
    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr i64 val() const {
        return x;
    }
    explicit constexpr operator i64() const {
        return x;
    }
    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong& operator*=(MLong rhs)& {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong& operator+=(MLong rhs)& {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong& operator-=(MLong rhs)& {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong& operator/=(MLong rhs)& {
        return *this *= rhs.inv();
    }
    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream& operator>>(std::istream& is, MLong& a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const MLong& a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
i64 MLong<0LL>::Mod = i64(1E18) + 9;

template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{ norm(x % getMod()) } {}

    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        }
        else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt& operator*=(MInt rhs)& {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt& operator+=(MInt rhs)& {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt& operator-=(MInt rhs)& {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt& operator/=(MInt rhs)& {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream& operator>>(std::istream& is, MInt& a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const MInt& a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
int MInt<0>::Mod = 998244353;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = mod;
using Z = MInt<P>;

void solve() {
    int n;std::cin >> n;
    std::vector<pii> info(n);
    for (auto& [a, b] : info)std::cin >> a >> b;
    for (int i = 0;i < n;++i) {
        auto [a, b] = info[i];
        if (a != -1 && a + b != i + 1) {
            std::cout << 0;
            return;
        }
    }
    if (n < 11) {
        std::cout << 0;
        return;
    }
    std::vector<std::vector<Z>> dp1(12, std::vector<Z>(12));
    dp1[0][0] = 1;
    auto vaild = [&](int a, int b) {return 0 <= a && a <= 10 && 0 <= b && b <= 10;};
    if (n <= 20) {
        auto [la, lb] = info.back();
        if (la != -1 && la != 11 && lb != 11) {
            std::cout << 0;
            return;
        }
        for (int sum = 1;sum < n;++sum) {
            auto [a, b] = info[sum - 1];
            // Z s = 0;
            for (int i = 0;i <= sum;++i) {
                int j = sum - i;
                if (!vaild(i, j))continue;
                if (a != -1 && i != a && j != a)continue;
                if (i)dp1[i][j] += dp1[i - 1][j];
                if (j)dp1[i][j] += dp1[i][j - 1];
                // std::cout << i << ' ' << j << ' ' << dp1[i][j] << '\n';
            }
        }

        Z ans = dp1[10][n - 11] + dp1[n - 11][10];
        std::cout << ans;
        return;
    }
    if (n % 2) {
        std::cout << 0;
        return;
    }
    for (int sum = 1;sum <= 20;++sum) {
        auto [a, b] = info[sum - 1];
        for (int i = 0;i <= sum;++i) {
            int j = sum - i;
            if (!vaild(i, j))continue;
            if (a != -1 && i != a && j != a)continue;
            if (i)dp1[i][j] += dp1[i - 1][j];
            if (j)dp1[i][j] += dp1[i][j - 1];
        }
    }
    // std::cout << dp1[10][10] << ' ';
    std::vector<Z> dp(n + 1); // 00 01 10
    dp[20] = dp1[10][10];
    for (int sum = 21;sum < n;++sum) {
        auto [a, b] = info[sum - 1];
        if (sum % 2) {
            if (a != -1 && a != sum / 2 && b != sum / 2) {
                std::cout << 0;
                return;
            }
            dp[sum] = dp[sum - 1] * 2;
        }
        else {
            if (a != -1 && a != sum / 2) {
                std::cout << 0;
                return;
            }
            dp[sum] = dp[sum - 1];
        }
    }
    auto [a, b] = info[n - 1];
    if (a != -1 && a != n / 2 + 2 && b != n / 2 + 2)std::cout << 0;
    else std::cout << dp[n - 1];
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