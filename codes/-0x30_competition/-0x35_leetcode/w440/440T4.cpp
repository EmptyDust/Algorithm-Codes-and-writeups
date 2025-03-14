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
    int x;
    Info(int x) :x(x) {};
    Info() :x(inf) {};
};
Info operator+(Info a, Info b) {
    Info c(std::min(a.x, b.x));
    return c;
}


void solve() {
    int n;std::cin >> n;
    std::vector<int> fruits(n), baskets(n);
    for (int& x : fruits)std::cin >> x;
    for (int& x : baskets)std::cin >> x;
    std::vector all(fruits);
    for (int x : baskets)all.push_back(x);
    ranges::sort(all);
    std::map<int, int> mp;
    for (int i = 0;i < 2 * n;++i) {
        mp[all[i]] = i;
        // std::cout << all[i] << ' ' << i << '\n';
    }
    std::vector pos(2 * n, std::vector<int>());
    for (int& x : fruits)x = mp[x];
    for (int& x : baskets)x = mp[x];
    for (int i = n - 1;i >= 0;--i) {
        pos[baskets[i]].push_back(i);
        // std::cout << baskets[i] << ' ';
    }
    SegmentTree<Info> sgt(2 * n);
    for (int i = 0;i < 2 * n;++i) {
        if (pos[i].size()) {
            sgt.modify(i, pos[i].back());
            // std::cout << i << ' ' << pos[i].back() << '\n';
            pos[i].pop_back();
        }
        else sgt.modify(i, inf);
    }
    int ans = 0;
    for (int f : fruits) {
        int p = sgt.rangeQuery(f, 2 * n).x;
        // std::cout << p << ' ';
        if (p == inf)ans++;
        else {
            int x = baskets[p];
            if (pos[x].size()) {
                sgt.modify(x, pos[x].back());
                pos[x].pop_back();
            }
            else sgt.modify(x, inf);
        }
    }
    std::cout << ans;
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