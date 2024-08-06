#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct Info {
    i64 sum = 0, l = 0, r = 0, ans = 0;
    Info(i64 x = -1e17) :sum(x), l(x), r(x), ans(x) {}
    Info operator+ (const Info& x) {
        Info res = Info(0);
        res.sum = x.sum + sum;
        res.l = std::max(l, sum + x.l);
        res.r = std::max(x.r, x.sum + r);
        res.ans = std::max({ ans,x.ans,r + x.l });
        return res;
    }
};

struct segment_tree
{
    std::vector<Info> tree;
    int size;
    segment_tree(int n) {
        size = n;
        tree.assign(n << 2, Info());
    }
    void update(int p, Info x) { update(p, x, 1, size, 1); };
    void update(int p, Info x, int l, int r, int i) {
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

    Info query(int ql, int qr) { return query(ql, qr, 1, size, 1); };
    Info query(int ql, int qr, int l, int r, int i) {
        if (l > r) return Info();
        if (qr < l || r < ql)return Info();
        if (ql <= l && r <= qr)return tree[i];
        int mid = l + r >> 1;
        return query(ql, qr, l, mid, i << 1) + query(ql, qr, mid + 1, r, i << 1 | 1);
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    segment_tree tree(n);
    for (int i = 0;i < n;++i) {
        tree.update(i + 1, a[i]);
    }
    int q;std::cin >> q;
    while (q--) {
        int op;std::cin >> op;
        if (op) {
            int l, r;std::cin >> l >> r;
            std::cout << tree.query(l, r).ans << '\n';
        }
        else {
            int x, y;std::cin >> x >> y;
            tree.update(x, y);
        }
    }
    return 0;
}