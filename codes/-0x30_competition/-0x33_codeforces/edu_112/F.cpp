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

template<class T> struct Segt {
    struct node {
        int l, r;
        T w, rmq, lazy;
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
                t[k] = { l, r, w[l], w[l], 0 }; // 如果有赋值为 0 的操作，则懒标记必须要 -1
                return;
            }
            t[k] = { l, r, 0, 0, 0 };
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
            p.rmq = std::min(l.rmq, r.rmq); // RMQ -> min/max
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
        T ans = std::numeric_limits<T>::max(); // RMQ -> 为 max 时需要修改为 ::lowest()
        if (l <= mid) ans = std::min(ans, rmq(l, r, GL)); // RMQ -> min/max
        if (mid < r) ans = std::min(ans, rmq(l, r, GR)); // RMQ -> min/max
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
        std::cout << "Min = " << t[k].rmq << ", ";
        std::cout << "lazy = " << t[k].lazy << ", ";
        std::cout << std::endl;
        if (t[k].l == t[k].r) return;
        debug(GL), debug(GR);
    }
};


void solve() {
    int n, m;std::cin >> n >> m;
    Segt<int> segt(m);
    std::vector<a3> info(n);
    for (auto& [w, l, r] : info)std::cin >> l >> r >> w, r--;
    ranges::sort(info);
    int ans = 1e9;
    for (int i = 0, j = 0;i < n;++i) {
        while (j < n && segt.rmq(1, m - 1) == 0) {
            auto [_, l, r] = info[j];
            segt.modify(l, r, 1);
            j++;
        }
        if (segt.rmq(1, m - 1)) {
            ans = std::min(ans, info[j - 1][0] - info[i][0]);
        }
        auto [_, l, r] = info[i];
        segt.modify(l, r, -1);
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