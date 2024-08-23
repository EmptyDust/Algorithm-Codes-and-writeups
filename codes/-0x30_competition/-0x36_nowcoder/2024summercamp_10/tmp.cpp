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

struct Info {
    Info operator+ (const Info& x) {

    }
}tree[MAXN << 2];

int n;
void update(int p, int x, int l = 1, int r = n, int i = 1) {
    if (l > r) return;
    if (p < l || r < p) return;
    if (l == r) {
        tree[i] = Info();
        return;
    }
    int mid = l + r >> 1;
    update(p, x, l, mid, i << 1);
    update(p, x, mid + 1, r, i << 1 | 1);
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

Info query(int ql, int qr, int l = 1, int r = n, int i = 1) {
    if (l > r) return Info();
    if (qr < l || r < ql)return Info();
    if (ql <= l && r <= qr)return tree[i];
    int mid = l + r >> 1;
    return query(ql, qr, l, mid, i << 1) + query(ql, qr, mid + 1, r, i << 1 | 1);
}


struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    struct Node {
        int len;
        int link;
        std::array<int, ALPHABET> next;
        Node() : len{ 0 }, link{ 0 }, next{} {}
    };

    std::vector<Node> t;

    AhoCorasick() {
        init();
    }

    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }

    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }

    int add(const std::string& a) {
        int p = 1;
        for (auto c : a) {
            int x = c - 'a';
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        return p;
    }

    void get_fail() {
        std::queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < ALPHABET; i++) {
                if (t[x].next[i] == 0) {
                    t[x].next[i] = t[t[x].link].next[i];
                }
                else {
                    t[t[x].next[i]].link = t[t[x].link].next[i];
                    q.push(t[x].next[i]);
                }
            }
        }
    }

    std::vector<int> work(std::string s) {
        get_fail();
        int p = 1;
        std::vector<int> f(t.size());
        for (auto c : s) {
            p = next(p, c - 'a');
            f[p]++;
        }

        std::vector<std::vector<int>> adj(t.size());
        for (int i = 2; i < t.size(); i++) {
            adj[link(i)].push_back(i);
        }

        std::function<void(int)> dfs = [&](int x) -> void {
            for (auto y : adj[x]) {
                dfs(y);
                f[x] += f[y];
            }
            };
        dfs(1);
        return f;
    }

    int next(int p, int x) {
        return t[p].next[x];
    }

    int link(int p) {
        return t[p].link;
    }

    int len(int p) {
        return t[p].len;
    }

    int size() {
        return t.size();
    }
};

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

auto l = l, r = r;
auto check = [&](auto x)->bool {

    };
while (l < r) {
    auto mid = l + r >> 1;
    if (check(mid))r = mid;
    else l = mid + 1;
}

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

void solve() {

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