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


struct Node {
    i64 sum = 0, f = 0, lmax = 0, rmax = 0;

    Node() = default;

    Node(i64 v) : sum(v), f(v), lmax(v), rmax(v) {}

    Node operator+(const Node& other) const {
        Node res;
        res.sum = sum + other.sum;
        res.f = std::max({ f, other.f, rmax + other.lmax });
        res.rmax = std::max(other.rmax, other.sum + rmax);
        res.lmax = std::max(lmax, sum + other.lmax);
        return res;
    }
};

int n;
template<class T>
class SegmentTree {
public:
    std::vector<T> tree;

    SegmentTree(std::vector<i64>& a) {
        n = a.size() - 1;
        tree.resize(4 * n);
        build(1, 1, n, a);
    }

    void build(int dep, int l, int r, const std::vector<i64>& a) {
        if (l == r) {
            tree[dep] = T(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(dep << 1, l, mid, a);
        build(dep << 1 | 1, mid + 1, r, a);
        push_up(dep);
    }

    void update(int pos, i64 val, int dep = 1, int l = 1, int r = n) {
        // std::cout << pos << ' ' << r << '\n';
        if (l == r) {
            tree[dep] = T(val);
            // std::cout << tree[dep].f << ' ';
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            update(pos, val, dep << 1, l, mid);
        }
        else {
            update(pos, val, dep << 1 | 1, mid + 1, r);
        }
        push_up(dep);
    }

    T query(int ql, int qr, int dep = 1, int l = 1, int r = n) {
        if (ql <= l && r <= qr) {
            return tree[dep];
        }
        int mid = (l + r) >> 1;
        T res;
        if (ql <= mid) {
            res = query(ql, qr, dep << 1, l, mid);
        }
        if (qr > mid) {
            res = res + query(ql, qr, dep << 1 | 1, mid + 1, r);
        }
        return res;
    }

    void push_up(int dep) {
        tree[dep] = tree[dep << 1] + tree[dep << 1 | 1];
    }
};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> b(n), a1(n), a2(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    if (n == 1) {
        std::cout << 0 << '\n';
        for (int i = 1; i <= q; ++i) {
            int pos, val;
            std::cin >> pos >> val;
            std::cout << 0 << '\n';
        }
        return;
    }
    n--;
    for (int i = 1;i <= n;++i) {
        a1[i] = b[i] - b[i - 1] - 1;
        a2[i] = -(b[i] - b[i - 1]) - 1;
    }
    SegmentTree<Node> seg1(a1);
    SegmentTree<Node> seg2(a2);
    auto query = [&]() {
        return std::max({ 0ll,seg1.query(1, n, 1, 1, n).f, seg2.query(1, n, 1, 1, n).f });
        };

    std::cout << query() << '\n';
    for (int i = 1; i <= q; ++i) {
        int pos, val;
        std::cin >> pos >> val;
        b[pos - 1] = val;
        if (pos > 1) {
            a1[pos - 1] = b[pos - 1] - b[pos - 2] - 1;
            seg1.update(pos - 1, a1[pos - 1], 1, 1, n);
            a2[pos - 1] = -(b[pos - 1] - b[pos - 2]) - 1;
            seg2.update(pos - 1, a2[pos - 1], 1, 1, n);
        }
        if (pos <= n) {
            // std::cout << n << ' ';
            a1[pos] = b[pos] - b[pos - 1] - 1;
            seg1.update(pos, a1[pos], 1, 1, n);
            a2[pos] = -(b[pos] - b[pos - 1]) - 1;
            seg2.update(pos, a2[pos], 1, 1, n);
        }
        std::cout << query() << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}