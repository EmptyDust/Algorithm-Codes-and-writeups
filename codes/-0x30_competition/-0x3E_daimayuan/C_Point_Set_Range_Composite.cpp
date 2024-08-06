#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;

//a1*a2*x+a1*b2+b1

//a1*(a2*x+b2)+b1

struct Mi64 {
    i64 value;
    Mi64() {}
    Mi64(i64 value) { this->value = value; }
    Mi64 operator * (const i64 w) {
        return value * w % mod;
    }
    Mi64 operator * (const Mi64 w) {
        return value * w.value % mod;
    }
    Mi64 operator + (const Mi64 w) {
        return (value + w.value) % mod;
    }
    Mi64 operator - (const Mi64 w) {
        return((value - w.value) % mod + mod) % mod;
    }
    bool operator == (const Mi64 w) {
        return value == w.value;
    }
};

struct Info {
    Mi64 a, b;
    Info(Mi64 a = 1, Mi64 b = 0) :a(a), b(b) {}
    Info operator+ (const Info& x) {
        Info res = Info();
        res.a = a * x.a;
        res.b = b * x.a + x.b;
        return res;
    }
    Mi64 cal(Mi64 x) {
        return a * x + b;
    }
    void print() {
        std::cout << a.value << ' ' << b.value << '\n';
    }
};

template <class T>
struct segment_tree
{
    std::vector<T> tree;
    int size;
    segment_tree(int n) {
        size = n;
        tree.assign(n << 2, T());
    }
    void update(int p, T x) { update(p, x, 1, size, 1); };
    void update(int p, T x, int l, int r, int i) {
        if (l > r) return;
        if (p < l || r < p) return;
        if (l == r) {
            tree[i] = x;
            return;
        }
        int mid = l + r >> 1;
        update(p, x, l, mid, i << 1);
        update(p, x, mid + 1, r, i << 1 | 1);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    T query(int ql, int qr) { return query(ql, qr, 1, size, 1); };
    T query(int ql, int qr, int l, int r, int i) {
        if (l > r) return T();
        if (qr < l || r < ql)return T();
        if (ql <= l && r <= qr)return tree[i];
        int mid = l + r >> 1;
        return query(ql, qr, l, mid, i << 1) + query(ql, qr, mid + 1, r, i << 1 | 1);
    }
};


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;std::cin >> n >> q;
    segment_tree<Info> tree(n);
    for (int i = 1;i <= n;++i) {
        int a, b;std::cin >> a >> b;
        tree.update(i, Info(a, b));
    }
    while (q--) {
        int op;std::cin >> op;
        if (op) {
            int l, r, x;std::cin >> l >> r >> x;l++;
            std::cout << tree.query(l, r).cal(x).value << '\n';
        }
        else {
            int p, c, d;std::cin >> p >> c >> d;p++;
            tree.update(p, Info(c, d));
        }
    }
    return 0;
}