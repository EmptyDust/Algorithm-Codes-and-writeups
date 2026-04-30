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

constexpr int P = 1000000007;
using Z = MInt<P>;


void solve() {
    int n, l, k;std::cin >> n >> l >> k;
    std::vector<Z> ans(n), stop(n), p(l + 1);
    for (int j = 0;j < n;++j) {
        Z sum = Z(l / n + (j < l % n)) / l;
        // Z sum = Z(1) / l;
        stop[j] = sum;
        ans[j] += sum;
        // std::cout << sum << ' ';
    }
    // std::cout << '\n';
    for (int i = 1;i < l;++i) {
        std::vector<Z> ns(n);
        int c = l - i;
        Z add = 0;
        int x = c / n;
        int lst = c % n;
        for (int j = 0;j < n;++j) {
            auto mul = stop[j] / c;
            add += mul * x;
            for (int k = 0, pos = (j + 1) % n;k < lst;++k, pos = (pos + 1) % n) {
                ns[pos] += mul;
            }
        }
        stop = ns;
        for (int j = 0;j < n;++j) {
            ans[j] += stop[j] += add;
            // std::cout << stop[j] << ' ';
        }
        // std::cout << '\n';
    }
    // std::queue<Z> res;
    // Z sum = 1;int idx = 0;
    // for (int j = 0;j < l;++j) {
    //     res.push(Z(1) / l);
    //     ans[j] += sum;
    // }
    // sum -= res.front();
    // res.pop();
    // for (int i = 1;i < l;++i) {
    //     for (int j = 0;j < l;++j, idx = (idx + 1) % n) {
    //         ans[idx] += sum;
    //         res.push(sum);
    //         sum += sum;
    //         sum -= res.front();
    //         res.pop();
    //         assert(res.size() == l - i);
    //         std::cout << res.size() << ' ';
    //     }
    //     std::cout << '\n';
    //     sum -= res.front();
    //     res.pop();
    // }
    // for (int j = 0;j < l;++j) {
    //     // Z sum = Z(l / n + (j < l % n)) / l;
    //     Z sum = Z(1) / l;
    //     stop[j] = sum;
    //     ans[j % n] += sum;
    //     std::cout << sum << ' ';
    // }
    // std::cout << std::endl;
    // for (int i = 1;i < l;++i) {
    //     int c = l - i;
    //     std::vector<Z> tmp(stop);
    //     for (int i = 1;i < tmp.size();++i) {
    //         tmp[i] += tmp[i - 1];
    //         // std::cout << tmp[i] << ' ';
    //     }
    //     Z sum = 0;
    //     for (auto x : stop)sum += x;
    //     stop[i - 1] = 0;
    //     for (int j = i;j < l + i;++j) {
    //         int R = j - 1, L = j - c;
    //         Z sum = 0;
    //         if (R >= 0) {
    //             if (L > 0) {
    //                 sum = (tmp[R] - tmp[L - 1]) / c;
    //             }
    //             else sum = tmp[R] / c;
    //         }
    //         ans[j % n] += sum;
    //         stop[j] = sum;
    //         // std::cout << L << ' ' << R << '\n';
    //     }
    //     for (auto x : stop)std::cout << x << ' ';
    //     std::cout << std::endl;
    // }
    // // std::cout << Z(1) / 5 << ' ' << Z(2) / 5 << '\n';
    for (int i = 0;i < n;++i)std::cout << ans[i] << ' ';
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