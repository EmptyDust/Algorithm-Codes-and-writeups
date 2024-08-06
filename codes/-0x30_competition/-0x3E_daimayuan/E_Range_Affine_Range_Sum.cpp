#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;

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

struct Lazy_tag {
public:
    Mi64 a, b;
    Lazy_tag(Mi64 a = 1, Mi64 b = 0) :a(a), b(b) {}
    Lazy_tag operator+ (const Lazy_tag& x) {
        Lazy_tag res = Lazy_tag();
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

struct Info {
    Mi64 num, len;
    Info(Mi64 x = 0, Mi64 l = 0) :num(x), len(l) {}
    Info operator+ (const Info& x) {
        return Info(num + x.num, len + x.len);
    }
    Info operator* (const Lazy_tag& x) {
        return Info(num * x.a + len * x.b, len);
    }
    void print() {
        std::cout << num.value << ' ' << len.value << '\n';
    }
};

struct lazy_segment_tree
{
    std::vector<Info> tree;
    std::vector<Lazy_tag> lazy;
    int size;
    lazy_segment_tree(std::vector<Info>& a) {
        int n = a.size();
        size = n;
        tree.assign(n << 3, Info());
        lazy.assign(n << 3, Lazy_tag());
        for (int i = 0;i < n;++i) {
            build(i + 1, a[i]);
        }
    }
    void build(int p, Info x) { build(p, p, x, 1, size, 1); };
    void build(int ul, int ur, Info x, int l, int r, int i) {
        if (l > r) return;
        if (ur < l || r < ul) return;
        if (ul <= l && r <= ur) {
            tree[i] = x;
            return;
        }
        int mid = l + r >> 1;
        build(ul, ur, x, l, mid, i << 1);
        build(ul, ur, x, mid + 1, r, i << 1 | 1);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void push_down(int x) {
        tree[x << 1] = tree[x << 1] * lazy[x];
        tree[x << 1 | 1] = tree[x << 1 | 1] * lazy[x];
        lazy[x << 1] = lazy[x << 1] + lazy[x];
        lazy[x << 1 | 1] = lazy[x << 1 | 1] + lazy[x];
        lazy[x] = Lazy_tag();
    }

    void update(int p, Lazy_tag x) { update(p, p, x, 1, size, 1); };
    void update(int l, int r, Lazy_tag x) { update(l, r, x, 1, size, 1); };
    void update(int ul, int ur, Lazy_tag x, int l, int r, int i) {
        if (l > r) return;
        if (ur < l || r < ul) return;
        if (ul <= l && r <= ur) {
            tree[i] = tree[i] * x;
            lazy[i] = lazy[i] + x;
            return;
        }
        push_down(i);
        int mid = l + r >> 1;
        update(ul, ur, x, l, mid, i << 1);
        update(ul, ur, x, mid + 1, r, i << 1 | 1);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    Info query(int ql, int qr) { return query(ql, qr, 1, size, 1); };
    Info query(int ql, int qr, int l, int r, int i) {
        if (l > r) return Info();
        if (qr < l || r < ql)return Info();
        if (ql <= l && r <= qr)return tree[i];
        push_down(i);
        int mid = l + r >> 1;
        return query(ql, qr, l, mid, i << 1) + query(ql, qr, mid + 1, r, i << 1 | 1);
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;std::cin >> n >> q;
    std::vector<Info> a(n);
    for (Info& x : a) {
        int y;
        std::cin >> y;
        x = Info(y, 1);
    }
    lazy_segment_tree tree(a);
    // tree.update(1, 2, Lazy_tag(100, 101));
    // std::cout << tree.query(2, 2).num.value << '\n';
    // tree.update(1, 1, Lazy_tag(100, 101));
    // std::cout << tree.query(1, 2).num.value;

    while (q--) {
        int op;std::cin >> op;
        if (op) {
            int l, r;std::cin >> l >> r;l++;
            std::cout << tree.query(l, r).num.value << '\n';
        }
        else {
            int l, r, b, c;std::cin >> l >> r >> b >> c;l++;
            tree.update(l, r, Lazy_tag(b, c));
        }
    }
    return 0;
}