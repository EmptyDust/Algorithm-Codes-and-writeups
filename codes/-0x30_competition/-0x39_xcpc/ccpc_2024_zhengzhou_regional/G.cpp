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

const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

using i64 = long long;

template<class T> constexpr T mypow(T n, i64 k) {
    T r = 1;
    for (; k; k /= 2, n *= n) {
        if (k % 2) {
            r *= n;
        }
    }
    return r;
}

template<class T> constexpr T power(int n) {
    return mypow(T(2), n);
}

template<const int& MOD> struct Zmod {
    int x;
    Zmod(signed x = 0) : x(norm(x% MOD)) {}
    Zmod(i64 x) : x(norm(x% MOD)) {}

    constexpr int norm(int x) const noexcept {
        if (x < 0) [[unlikely]] {
            x += MOD;
        }
        if (x >= MOD) [[unlikely]] {
            x -= MOD;
        }
        return x;
    }
    explicit operator int() const {
        return x;
    }
    constexpr int val() const {
        return x;
    }
    constexpr Zmod operator-() const {
        Zmod val = norm(MOD - x);
        return val;
    }
    constexpr Zmod inv() const {
        assert(x != 0);
        return mypow(*this, MOD - 2);
    }
    friend constexpr auto& operator>>(std::istream& in, Zmod& j) {
        int v;
        in >> v;
        j = Zmod(v);
        return in;
    }
    friend constexpr auto& operator<<(std::ostream& o, const Zmod& j) {
        return o << j.val();
    }
    constexpr Zmod& operator++() {
        x = norm(x + 1);
        return *this;
    }
    constexpr Zmod& operator--() {
        x = norm(x - 1);
        return *this;
    }
    constexpr Zmod operator++(signed) {
        Zmod res = *this;
        ++*this;
        return res;
    }
    constexpr Zmod operator--(signed) {
        Zmod res = *this;
        --*this;
        return res;
    }
    constexpr Zmod& operator+=(const Zmod& i) {
        x = norm(x + i.x);
        return *this;
    }
    constexpr Zmod& operator-=(const Zmod& i) {
        x = norm(x - i.x);
        return *this;
    }
    constexpr Zmod& operator*=(const Zmod& i) {
        x = i64(x) * i.x % MOD;
        return *this;
    }
    constexpr Zmod& operator/=(const Zmod& i) {
        return *this *= i.inv();
    }
    constexpr Zmod& operator%=(const int& i) {
        return x %= i, *this;
    }
    friend constexpr Zmod operator+(const Zmod i, const Zmod j) {
        return Zmod(i) += j;
    }
    friend constexpr Zmod operator-(const Zmod i, const Zmod j) {
        return Zmod(i) -= j;
    }
    friend constexpr Zmod operator*(const Zmod i, const Zmod j) {
        return Zmod(i) *= j;
    }
    friend constexpr Zmod operator/(const Zmod i, const Zmod j) {
        return Zmod(i) /= j;
    }
    friend constexpr Zmod operator%(const Zmod i, const int j) {
        return Zmod(i) %= j;
    }
    friend constexpr bool operator==(const Zmod i, const Zmod j) {
        return i.val() == j.val();
    }
    friend constexpr bool operator!=(const Zmod i, const Zmod j) {
        return i.val() != j.val();
    }
    friend constexpr bool operator<(const Zmod i, const Zmod j) {
        return i.val() < j.val();
    }
    friend constexpr bool operator>(const Zmod i, const Zmod j) {
        return i.val() > j.val();
    }
};

int MOD[] = { 998244353, 1000000007 };
using Z = Zmod<MOD[1]>;

const int N = 1 << 21;
static const int mod1 = 1E9 + 7;
static const int mod2 = 1E9 + 9;
using U = Zmod<mod1>;
using V = Zmod<mod2>;
U base1 = 200003;
V base2 = 200017;

struct Hash {
    U hash1;
    V hash2;
    // std::string s;

    Hash(i64 x) : hash1{ mypow(base1, x) }, hash2{ mypow(base2, x) } {}
    Hash(U hash1, V hash2) : hash1{ hash1 }, hash2{ hash2 } {}

    Hash operator+(Hash h) {
        return Hash(hash1 + h.hash1, hash2 + h.hash2);
    }

    Hash operator+(int v) {
        return Hash(hash1 * mypow(base1, v), hash2 * mypow(base2, v));
    }

    Hash inv() {
        return Hash(hash1.inv(), hash2.inv());
    }
};

template<class T> struct Segt {
    struct node {
        int l, r;
        T w, rmq, lazy;
        Hash mul, inv;
    };
    std::vector<T> w;
    std::vector<node> t;

    Segt() {}
    Segt(int n) { init(n); }
    Segt(std::vector<int> in) {
        int n = in.size() - 1;
        w.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            w[i] = in[i];
        }
        init(in.size() - 1);
    }

#define GL (k << 1)
#define GR (k << 1 | 1)

    void init(int n) {
        w.resize(n + 1);
        t.resize(n * 4 + 1);
        auto build = [&](auto self, int l, int r, int k = 1) {
            if (l == r) {
                t[k] = { l, r, w[l], w[l], 0, Hash(w[l]), Hash(w[l]).inv() }; // 如果有赋值为 0 的操作，则懒标记必须要 -1
                return;
            }
            t[k] = { l, r, 0, 0, 0, Hash(0), Hash(0) };
            int mid = (l + r) / 2;
            self(self, l, mid, GL);
            self(self, mid + 1, r, GR);
            pushup(k);
            };
        build(build, 1, n);
    }
    void pushdown(node& p, T lazy) { /* 【在此更新下递函数】 */
        p.w += (p.r - p.l + 1) * lazy;
        p.rmq += lazy;
        p.lazy += lazy;
        // p.mul = p.mul + lazy;
        // p.inv = p.inv + lazy;
    }
    void pushdown(int k) {
        if (t[k].lazy == 0) return;
        pushdown(t[GL], t[k].lazy);
        pushdown(t[GR], t[k].lazy);
        t[k].lazy = 0;
    }
    void pushup(int k) {
        auto pushup = [&](node& p, node& l, node& r) { /* 【在此更新上传函数】 */
            p.w = l.w + r.w;
            p.rmq = std::max(l.rmq, r.rmq); // RMQ -> min/max
            // p.mul = l.mul + r.mul;
            // p.inv = r.inv + l.inv;
            };
        pushup(t[k], t[GL], t[GR]);
    }
    void modify(int l, int r, T val, int k = 1) { // 区间修改
        if (l <= t[k].l && t[k].r <= r) {
            pushdown(t[k], val);
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        if (l <= mid) modify(l, r, val, GL);
        if (mid < r) modify(l, r, val, GR);
        pushup(k);
    }
    T rmq(int l, int r, int k = 1) { // 区间询问最小值
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].rmq;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = std::numeric_limits<T>::min(); // RMQ -> 为 max 时需要修改为 ::lowest()
        if (l <= mid) ans = std::max(ans, rmq(l, r, GL)); // RMQ -> min/max
        if (mid < r) ans = std::max(ans, rmq(l, r, GR)); // RMQ -> min/max
        return ans;
    }
    T ask(int l, int r, int k = 1) { // 区间询问
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].w;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = 0;
        if (l <= mid) ans += ask(l, r, GL);
        if (mid < r) ans += ask(l, r, GR);
        return ans;
    }
    void debug(int k = 1) {
        std::cout << "[" << t[k].l << ", " << t[k].r << "]: ";
        std::cout << "w = " << t[k].w << ", ";
        std::cout << "Max = " << t[k].rmq << ", ";
        std::cout << "lazy = " << t[k].lazy << ", ";
        std::cout << std::endl;
        if (t[k].l == t[k].r) return;
        debug(GL), debug(GR);
    }
};

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x, x++;
    Segt<i64> segt(a);
    while (q--) {
        int op, L, R;std::cin >> op >> L >> R;
        if (op == 1) {
            int v;std::cin >> v;
            segt.modify(L, R, v);
            segt.debug();
        }
        else {

        }
    }
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