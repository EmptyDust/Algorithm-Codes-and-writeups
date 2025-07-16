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

using namespace std;
template<class T> struct Segt {
    struct node {
        int l, r;
        T w, gcd, lcm, lazy;
    };
    vector<T> w;
    vector<node> t;

    Segt() {}
    Segt(int n) { init(n); }
    Segt(vector<int> in) {
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
                t[k] = { l, r, w[l], w[l], w[l], -1 }; // 如果有赋值为 0 的操作，则懒标记必须要 -1
                return;
            }
            t[k] = { l, r, 0, 0, 0, -1 };
            int mid = (l + r) / 2;
            self(self, l, mid, GL);
            self(self, mid + 1, r, GR);
            pushup(k);
            };
        build(build, 1, n);
    }
    void pushdown(node& p, T lazy) { /* 【在此更新下递函数】 */
        p.w = (p.r - p.l + 1) * lazy;
        p.gcd = p.lcm = p.lazy = lazy;
    }
    void pushdown(int k) {
        if (t[k].lazy == -1) return;
        pushdown(t[GL], t[k].lazy);
        pushdown(t[GR], t[k].lazy);
        t[k].lazy = -1;
    }
    void pushup(int k) {
        auto pushup = [&](node& p, node& l, node& r) { /* 【在此更新上传函数】 */
            p.w = l.w + r.w;
            p.gcd = std::__gcd(l.gcd, r.gcd);
            if (l.lcm == -1 || r.lcm == -1) p.lcm = -1;
            else p.lcm = l.lcm * r.lcm / std::__gcd(l.lcm, r.lcm);
            if (p.lcm > 2e9) p.lcm = -1;
            };
        pushup(t[k], t[GL], t[GR]);
    }
    void modify(int l, int r, T val, int k = 1) {
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
    void update(int l, int r, T val, int k = 1) {
        if (t[k].lcm != -1 && val % t[k].lcm == 0) return;
        if (l <= t[k].l && t[k].r <= r && t[k].gcd == t[k].lcm) {
            pushdown(t[k], std::__gcd(t[k].gcd, val));
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        if (l <= mid) update(l, r, val, GL);
        if (mid < r) update(l, r, val, GR);
        pushup(k);
    }
    // T rmq(int l, int r, int k = 1) { // 区间询问最小值
    //     if (l <= t[k].l && t[k].r <= r) {
    //         return t[k].rmq;
    //     }
    //     pushdown(k);
    //     int mid = (t[k].l + t[k].r) / 2;
    //     T ans = numeric_limits<T>::max(); // RMQ -> 为 max 时需要修改为 ::lowest()
    //     if (l <= mid) ans = min(ans, rmq(l, r, GL)); // RMQ -> min/max
    //     if (mid < r) ans = min(ans, rmq(l, r, GR)); // RMQ -> min/max
    //     return ans;
    // }
    T ask(int l, int r, int k = 1) { // 区间询问
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].w;
        }
        // std::cout << k << ' ' << t.size() << '\n';
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = 0;
        if (l <= mid) ans += ask(l, r, GL);
        if (mid < r) ans += ask(l, r, GR);
        return ans;
    }
    void debug(int k = 1) {
        cout << "[" << t[k].l << ", " << t[k].r << "]: ";
        cout << "w = " << t[k].w << ", ";
        cout << "gcd = " << t[k].gcd << ", ";
        cout << "lcm = " << t[k].lcm << ", ";
        cout << "lazy = " << t[k].lazy << ", ";
        cout << endl;
        if (t[k].l == t[k].r) return;
        debug(GL), debug(GR);
    }
};

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i) std::cin >> a[i];
    Segt<i64> segt(a);
    // segt.debug();
    while (q--) {
        int op, l, r, x;std::cin >> op >> l >> r >> x;
        if (op) {
            segt.update(l, r, x);
            std::cout << segt.ask(l, r) << '\n';
        }
        else {
            segt.modify(l, r, x);
        }
        // segt.debug();
        // std::cout << '\n';
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