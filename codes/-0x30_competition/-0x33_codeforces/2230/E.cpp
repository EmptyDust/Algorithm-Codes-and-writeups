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

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

template <class T>
struct SegmentTree {
    int n;
    std::vector<T> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, T v_ = T()) {
        init(n_, v_);
    }
    // template <class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, T v_ = T()) {
        init(std::vector(n_, v_));
    }
    // template <class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), T());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const T &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const T &v) {
        modify(1, 0, n, p, v);
    }
    T rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return T();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    T rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template <class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template <class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Info {
    int minx = inf; // x sum
};
Info operator+(Info a, Info b) {
    return Info{std::min(a.minx, b.minx)};
}

std::vector<Info> A(MAXN), B(MAXN);
SegmentTree<Info> segtA(A), segtB(B);

void solve() {
    int n;
    std::cin >> n;
    std::vector<a2> items(n);
    std::set<int> set;
    for (auto &[a, b] : items)
        std::cin >> a;
    for (auto &[a, b] : items)
        std::cin >> b;
    for (auto [a, b] : items) {
        A[a].minx = std::min(A[a].minx, b);
        B[b].minx = std::min(B[b].minx, a);
        segtA.modify(a, Info{A[a]});
        segtB.modify(b, Info{B[b]});
        set.insert(a + b);
    }

    int m;
    std::cin >> m;
    std::vector<a3> users(m);
    for (auto &[a, b, c] : users)
        std::cin >> a;
    for (auto &[a, b, c] : users)
        std::cin >> b;
    for (auto &[a, b, c] : users)
        std::cin >> c;

    auto query = [&](SegmentTree<Info> &segt, int l, int r, int t, int d) {
        int q = segt.rangeQuery(l, r).minx;
        if (q < t)
            return 0;
        if (q == inf)
            return inf;
        if (q > t + d)
            return t + d;
        return q;
    };

    // std::cout << segtA.rangeQuery(0, 33).minx << '\n';

    for (auto [tp, tc, d] : users) {
        int ansAl = query(segtA, 0, tp, tc, d);
        int ansAr = query(segtA, tp + d, N + 1, tc, d) + tp + d;
        int ansBl = query(segtB, 0, tc, tp, d);
        int ansBr = query(segtB, tc + d, N + 1, tp, d) + tc + d;
        auto it = set.lower_bound(tp + tc);
        int ansMid = (it == set.end()) ? inf : *it;
        int ansOut = tp + d + tc + d;
        int ans = std::min({ansAl, ansAr, ansBl, ansBr, ansMid, ansOut});
        // std::cout << ansAl << ' ' << ansAr << ' ' << ansBl << ' ' << ansBr << ' ' << ansMid << " " << ansOut << '\n';
        std::cout << ans << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}