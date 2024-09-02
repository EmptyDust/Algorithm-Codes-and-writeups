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

namespace ntt {
    using namespace std;
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

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<int> cnt(26);
    for (char ch : s)cnt[ch - 'a']++;
    std::vector<int> a(n + 1, 0); a[0] = 1;
    std::vector<i64> fact(n + 1, 0), invfact(n + 1, 0);
    fact[0] = invfact[0] = 1;
    for (int i = 1;i <= n;++i) {
        fact[i] = fact[i - 1] * i % mod;
        invfact[i] = inv(fact[i]);
    }
    for (int i = 0;i < 26;++i) {
        std::vector<int> m(n + 1, 0);
        for (int j = 0;j <= cnt[i];++j)m[j] = invfact[j];
        auto c = ntt::NTTMultiplier(a, m).multiply();
        for (int j = 1;j <= n;++j)
            a[i] = c[i];
    }
    for (int i = 1;i <= n;++i)std::cout << fact[i] * a[i] % mod << ' ';
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