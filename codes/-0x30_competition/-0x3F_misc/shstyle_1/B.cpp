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

std::vector ys(1e5 + 10, std::vector<int>());
std::vector<int> pos(1e5 + 10, -1);

void sieve(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1;i * j <= 1e5;++j) {
            ys[i * j].push_back(i);
        }
    }
}


struct Info {
    int x = 0;
    Info(int x) :x(x) {}
    Info() :x(0) {}
};

Info operator+(Info a, Info b) {
    return Info(std::max(a.x, b.x));
}


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

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), cur(n, n);
    for (int& x : a)std::cin >> x;
    int Q;std::cin >> Q;
    std::vector<a3> q(Q);int idx = 0;
    for (auto& [l, r, id] : q)std::cin >> l >> r, l--, id = idx++;
    ranges::sort(q);
    std::vector<int> ptr(n, 0), ans(Q);
    std::vector info(n, std::vector<pii>());
    std::vector del(n, std::vector<int>());
    for (int i = n - 1;i >= 0;--i)for (int y : ys[a[i]]) {
        // std::cout << pos[y] << ' ' << cur[i] << '\n';
        if (pos[y] != -1 && pos[y] < cur[i]) {
            info[pos[y]].push_back({ y,i });
            del[i].push_back(pos[y]);
            cur[i] = pos[y];
        }
        pos[y] = i;
    }
    SegmentTree<Info> sgt(n);
    sgt.modify(0, 1);
    // std::cout << sgt.rangeQuery(0, 1).x;
    for (int i = 0;i < n;++i) {
        ranges::sort(info[i], std::greater<pii>());
        if (info[i].size())
            sgt.modify(i, info[i][0].first);
    }

    std::vector<a3> c;int pre = 0;
    auto work = [&](int p) {
        // std::cout << p << ' ' << c.size() << '\n';
        for (;pre < p;pre++) for (auto x : del[pre]) {
            // std::cout << info[x][ptr[x]].second << ' ';
            if (ptr[x] < info[x].size() && info[x][ptr[x]].second < p) {
                while (ptr[x] < info[x].size() && info[x][ptr[x]].second < p) {
                    ptr[x]++;
                }
                if (ptr[x] == info[x].size()) {
                    sgt.modify(x, 1);
                }
                else sgt.modify(x, info[x][ptr[x]].first);
            }
        }
        // std::cout << '\n';
        for (auto [l, r, id] : c) {
            ans[id] = sgt.rangeQuery(l, r).x;
        }
        // for (int i = 0;i < n;++i) {
        //     std::cout << sgt.rangeQuery(i, i + 1).x << ' ';
        // }
        // std::cout << '\n';
        c.clear();
        };
    int pl = 0;
    for (auto [l, r, id] : q) {
        if (l != pl) {
            work(pl);
            pl = l;
        }
        c.push_back({ l,r,id });
    }
    work(pl);
    for (int& x : ans)std::cout << x << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    sieve(1e5 + 2);
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}