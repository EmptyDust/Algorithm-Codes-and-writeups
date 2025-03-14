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


namespace ntt {
    using namespace std;

    const long long mod = 998244353;
    const long long G = 3;
    const long long Gi = 332748118; // G 在模 p 意义下的逆元

    class P {
    public:
        long long a{};

        P() = default;

        [[nodiscard]] long long get() const {
            return a;
        }

        explicit P(long long p) {
            a = p % mod;
            if (a < 0) {
                a += mod;
            }
        };

        P operator+(const P& rhs) const {
            return P{ a + rhs.a };
        }

        P operator-(const P& rhs) const {
            return P{ a - rhs.a };
        }

        P operator*(const P& rhs) const {
            return P{ a * rhs.a };
        }

        [[nodiscard]] P pow(long long n) const {
            P bas = P(a);
            P res = P(1);
            while (n > 0) {
                if (n % 2 == 1) {
                    res = res * bas;
                }
                bas = bas * bas;
                n /= 2;
            }
            return res;
        }

        [[nodiscard]] P inverse() const {
            return pow(mod - 2);
        }
    };

    class NTTMultiplier {
    public:
        vector<int> input1;
        vector<int> input2;
        vector<int> bitInv;//位逆置换使用
        int size{};

        NTTMultiplier(const vector<int>& v1, const vector<int>& v2) {
            input1 = v1;
            input2 = v2;
            size = (int)(input1.size() + input2.size() - 1);
            int n = 1;
            while (n < size) {
                n <<= 1;
            }
            size = n;
            input1.resize(size);
            input2.resize(size);
            bitInv.resize(size);
            initBitInv();//位逆置换使用
        }

        void initBitInv() {
            bitInv[0] = 0;
            int log2n = (int)log2(size);
            for (int i = 1; i < size; i++) {
                int pre = (i & 1) << (log2n - 1);//第1位(奇数为1,偶数为0);
                int suf = bitInv[i >> 1] >> 1;   //第2到第n位(这是的递推公式);
                bitInv[i] = pre | suf;
            }
        }

        vector<int> multiply() {
            // 将输入转换为模数形式
            vector<P> nttInput1(input1.begin(), input1.end());
            vector<P> nttInput2(input2.begin(), input2.end());

            // 执行快速傅里叶变换
            fastNTT(nttInput1, false);
            fastNTT(nttInput2, false);
            // 对应位置相乘
            for (int i = 0; i < size; i++) {
                nttInput1[i] = nttInput1[i] * nttInput2[i];
            }
            // 执行反向快速傅里叶变换
            fastNTT(nttInput1, true);
            P invSize = P(size).inverse();
            for (int i = 0; i < size; i++) {
                nttInput1[i] = nttInput1[i] * invSize;
            }

            // 取实部并取整
            vector<int> result(size);
            for (int i = 0; i < size; i++) {
                result[i] = (int)nttInput1[i].get();
            }

            input1.clear();
            input2.clear();
            size = 0;

            return result;
        }


        void bitRev(vector<P>& arr) {
            for (int i = 1; i < arr.size(); i++) {
                if (i < bitInv[i]) {
                    swap(arr[i], arr[bitInv[i]]);        //交换
                }
            }
        }


        void fastNTT(vector<P>& data, bool inverse) {
            int n = (int)data.size();
            bitRev(data);
            P bas = inverse ? P(Gi) : P(G);
            for (int len = 2; len <= n; len *= 2) {
                long long angle = (long long)(mod - 1) / len;
                P wn = bas.pow(angle);
                for (int i = 0; i < n; i += len) {
                    P w(1);
                    for (int j = i; j < i + len / 2; j++) {
                        P evenVal = data[j];
                        P oddVal = data[j + len / 2] * w;
                        data[j] = evenVal + oddVal;
                        data[j + len / 2] = evenVal - oddVal;
                        w = w * wn;
                    }
                }
            }
        }

        void ntt(vector<P>& data, bool inverse) { // NOLINT(misc-no-recursion)
            int n = (int)data.size();
            if (n == 1) {
                return;
            }
            vector<P> even(n / 2);
            vector<P> odd(n / 2);
            // 分离奇偶项
            for (int i = 0; i < n / 2; i++) {
                even[i] = data[2 * i];
                odd[i] = data[2 * i + 1];
            }
            // 递归进行快速傅里叶变换
            ntt(even, inverse);
            ntt(odd, inverse);

            P bas = inverse ? P(Gi) : P(G);
            long long angle = (long long)(mod - 1) / n; // NOLINT(cppcoreguidelines-narrowing-conversions)
            P w(1);
            P wn = bas.pow(angle);
            // 合并结果
            for (int i = 0; i < n / 2; i++) {
                P evenVal = even[i];
                P oddVal = odd[i] * w;
                data[i] = evenVal + oddVal;
                data[i + n / 2] = evenVal - oddVal;
                w = w * wn;
            }
        }
    };
}

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

std::vector<int> fact(1, 1);
std::vector<int> inv_fact(1, 1);
i64 comb(int n, int k) {
    if (k<0 || k>n)return 0;
    while ((int)fact.size() < n + 1) {
        fact.push_back(1ll * fact.back() * (int)fact.size() % mod);
        inv_fact.push_back(inv(fact.back()));
    }
    return 1ll * fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

void solve() {
    int n, q;std::cin >> n >> q;
    std::string s;std::cin >> s;
    int cnt1 = std::count(s.begin(), s.end(), '1');
    int cnt0 = std::count(s.begin(), s.end(), '0');
    std::vector A(n + 1, 0), B(n + 1, 0), C(n + 1, 0);
    std::iota(A.begin(), A.end(), 0);
    std::iota(B.begin(), B.end(), 0);
    for (int i = 1;i <= n;++i) {

    }
    auto mul = ntt::NTTMultiplier(A, B).multiply();

    std::vector<Z> info(n + 1);
    for (int i = 2;i <= n;++i) {
        info[i] = info[i - 1] + mul[i];
    }
    // info[i] = info[i - 1] + sum(cnt[i - 1][j] * (mul[j + 1] - mul[j]))
    // info[i] = Cn0 * mul[0] + cn2 * mul[2] .. = n * (n - 1) *../1 * 2 * 3
    // 1 3 6 10
    for (auto& x : mul)std::cout << x << ' ';
    // for (int i = 2;i <= n;++i) {
    //     info[i] += info[i - 2];
    // }
    while (q--) {
        int x;std::cin >> x;x--;
        if (s[x] == '1')cnt1--, cnt0++, s[x] = '0';
        else cnt1++, cnt0--, s[x] = '1';
        int p = std::max(0, cnt1 - 2 * (cnt0 + 1));
        std::cout << cnt1 << ' ' << cnt0 << '\n';
        // std::cout << info[cnt1] << '\n';
        Z ans = 0;
        for (int i = 0;i <= cnt0 && cnt1 - 2 * i >= 0;++i) {
            ans += info[cnt1 - 2 * i] * comb(cnt0, i);
            std::cout << info[cnt1 - 2 * i] << ' ' << comb(cnt0, i) << '\n';
        }
        std::cout << ans << '\n';
        // std::cout << info[cnt1] - info[p] << '\n';
    }
}
//5
//4 + 6 = 20
//111110
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}