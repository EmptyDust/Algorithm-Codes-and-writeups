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

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
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
    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
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
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
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
struct Info {
    int max = -1;
    int min = -1;
};

int p[MAXN];
Info operator+(Info a, Info b) {
    Info c;
    if (a.max == -1)return b;
    if (b.max == -1)return a;
    if (p[a.max] >= p[b.max]) {
        c.max = a.max;
    }
    else {
        c.max = b.max;
    }
    if (p[a.min] <= p[b.min]) {
        c.min = a.min;
    }
    else {
        c.min = b.min;
    }
    return c;
}


void solve() {
    int n;std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> p[i];
    std::vector<int> suf(n), d(n + 1);
    std::vector<Info> info(n);
    std::vector<std::vector<int>> pos(n + 1);
    for (int i = n - 1;i >= 0;--i) {
        info[i] = { i,i };
        pos[p[i]].push_back(i);
        if (!d[p[i]]) {
            suf[i] = p[i];
            d[p[i]] = 1;
        }
    }

    SegmentTree<Info> sg(info);

    std::vector<int> ans;
    for (int i = 0, l = 0;i < n;++i) {
        while (d[suf[i]]) {
            if (ans.size() % 2) {
                l = sg.rangeQuery(l, i + 1).min;
                ans.push_back(p[l]);
                d[p[l]] = 0;
                for (auto x : pos[p[l]]) {
                    sg.modify(x, Info());
                }
                l++;
            }
            else {
                l = sg.rangeQuery(l, i + 1).max;
                ans.push_back(p[l]);
                d[p[l]] = 0;
                for (auto x : pos[p[l]]) {
                    sg.modify(x, Info());
                }
                l++;
            }
        }
        // std::cout << suf[i] << " ";
    }
    // std::cout << std::endl;
    std::cout << ans.size() << '\n';
    for (int x : ans)std::cout << x << " ";
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