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

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
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
    void apply(int p, const Tag& v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        }
        else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info& v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag& v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Tag {
    i64 a = 0, init = 0;
    void apply(Tag t) {
        if (t.init) {
            a = 0;
            init = 1;
        }
        a += t.a;
    }
};

int k;

struct Info {
    i64 x = 0;
    void apply(Tag t) {
        if (t.init) x = 0;
        x += t.a;
    }
};
Info operator+(Info a, Info b) {
    return { std::max(a.x, b.x) };
}


void solve() {
    int n;std::cin >> n;
    int pos = 0;
    std::vector<i64> a(n), p(n);
    std::vector<i64> sort;
    for (auto& x : a) std::cin >> x;
    a.push_back(a.back() + 1e9);n++;
    sort.push_back(0);
    for (int i = 1;i < n;++i) {
        p[i] = p[i - 1] + (a[i] - a[i - 1]) * 2 * (i % 2 ? 1 : -1);
        sort.push_back(p[i] - 1);
        sort.push_back(p[i]);
        sort.push_back(p[i] + 1);
    }
    ranges::sort(sort);
    sort.erase(std::unique(sort.begin(), sort.end()), sort.end());
    // for (auto x : p)std::cout << x << ' ';
    for (int i = 0;i < n;++i) p[i] = std::lower_bound(sort.begin(), sort.end(), p[i]) - sort.begin();
    int m = sort.size();
    LazySegmentTree<Info, Tag> sgt(m);
    std::vector<i64> dp(m);
    // sgt.rangeApply(0, 14, Tag(0, 1));
    // sgt.rangeApply(14, 16, Tag(1, 0));
    // sgt.rangeApply(16, m, Tag(0, 1));
    // std::cout << sgt.rangeQuery(0, m).x << '\n';
    for (int i = 1;i < n;++i) {
        // std::cout << p[i] << ' ';
        i64 x = p[i];
        i64 y = p[i - 1];
        if (i % 2) {
            sgt.rangeApply(0, y + 1, Tag(0, 1));
            sgt.rangeApply(y + 1, x + 1, Tag(1, 0));
            sgt.rangeApply(x + 1, m, Tag(0, 1));
        }
        else {
            sgt.rangeApply(0, x, Tag(0, 1));
            sgt.rangeApply(x, y, Tag(1, 0));
            sgt.rangeApply(y, m, Tag(0, 1));
        }
        // int d = sgt.rangeQuery(0, m).x;
        // dp[i] = std::max(dp[i - 1], dp[i - d] + d);
        // std::cout << x << " " << y << " " << dp[i] << ' ' << d << "\n";
    }
    std::cout << sgt.rangeQuery(0, m).x;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}