// #pragma GCC optimize("O2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse4,popcnt,abm,mmx")

#include <bits/stdc++.h>

#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
#define no do { cout << "No" << endl; return; } while(0)
#define yes do { cout << "Yes" << endl; return; } while (0)
#define lowbit(x) ((x) & -(x))

using namespace std;

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

template<typename T> ostream& operator << (ostream& out, const set<T>& obj) { out << "set(";for (auto it = obj.begin();it != obj.end();it++) out << (it == obj.begin() ? "" : ", ") << *it;out << ")";return out; }
template<typename T1, typename T2> ostream& operator << (ostream& out, const map<T1, T2>& obj) { out << "map(";for (auto it = obj.begin();it != obj.end();it++) out << (it == obj.begin() ? "" : ", ") << it->first << ": " << it->second;out << ")";return out; }
template<typename T1, typename T2> ostream& operator << (ostream& out, const pair<T1, T2>& obj) { out << "<" << obj.first << ", " << obj.second << ">";return out; }
template<typename T> ostream& operator << (ostream& out, const vector<T>& obj) { out << "vector(";for (auto it = obj.begin();it != obj.end();it++) out << (it == obj.begin() ? "" : ", ") << *it;out << ")";return out; }

namespace ntt {

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

const int mod = 998244353;

ll slowPow(ll a, ll b, ll m) {
    ll r = 1;
    while (b) {
        if (b & 1) r = (r * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) w[i] = w[i - 1] + slowPow(i, k, mod), w[i] %= mod;
    for (int i = 1; i <= n; i++) w[i] = w[i - 1] + w[i], w[i] %= mod;
    //out(w);
    const int inv = slowPow(2, mod - 2, mod);

    string r;
    ll ans = 0;
    auto calc = [&]() -> void {
        if (r.empty()) return;
        vector<int> pre(r.size() + 1);
        pre[0] = 1;
        for (int i = 1; i <= r.size(); i++) {
            pre[i] = pre[i - 1];
            char c = r[i - 1];
            if (c == '?') pre[i] = (1LL * pre[i] * inv) % mod;
        }
        vector<int> x(r.size()), y(r.size());
        for (int i = 0; i < r.size(); i++) {
            if (i && r[i - 1] == '1') continue;
            ll cur = slowPow(pre[i], mod - 2, mod);
            if (i && r[i - 1] == '?') cur *= inv, cur %= mod;
            x[i] = cur;
        }
        for (int i = 0;i < r.size();++i)std::cout << x[i] << " ";
        std::cout << '\n';
        for (int i = 0; i < r.size(); i++) y[i] = w[i + 1];
        vector<int> z(ntt::NTTMultiplier(x, y).multiply());
        for (int i = 0; i < r.size(); i++) {
            if (i + 1 < r.size() && r[i + 1] == '1') continue;
            ll cur = (1LL * z[i] * pre[i + 1]) % mod;
            if (i + 1 < r.size() && r[i + 1] == '?') cur *= inv, cur %= mod;
            ans += cur;
            ans %= mod;
        }
        /*
        for (int i = 1; i <= r.size(); i++) {
            for (int j = i; j <= r.size(); j++) {
                if (i - 2 >= 0 && r[i - 2] == '1') continue;
                if (j < r.size() && r[j] == '1') continue;
                ll cur = (pre[j] * slowPow(pre[i - 1], mod - 2, mod)) % mod;
                if (i - 2 >= 0 && r[i - 2] == '?') cur *= inv, cur %= mod;
                if (j < r.size() && r[j] == '?') cur *= inv, cur %= mod;
                cur *= w[j - i + 1], cur %= mod;
                //ans += cur, ans %= mod;
            }
        }
        */
        r.clear();
        };
    for (char c : s) {
        if (c == '0') {
            calc();
        }
        else {
            r.push_back(c);
        }
    }
    calc();
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
}