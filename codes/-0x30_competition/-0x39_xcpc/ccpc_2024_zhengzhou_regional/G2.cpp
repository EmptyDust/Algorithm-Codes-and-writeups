#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;

const i64 M1 = 1e9 + 7, B1 = 200003;
const i64 M2 = 998244353, B2 = 200009;

i64 qpow(i64 x, i64 b, i64 mod) {
    i64 ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
    return ret;
}

const i64 inv_B1 = qpow(B1, M1 - 2, M1);
const i64 inv_B2 = qpow(B2, M2 - 2, M2);

template<class T> struct Segt {
    struct node {
        int l, r;
        i64 h1, rev_h1;
        i64 h2, rev_h2;
        T w, lazy;

        i64 lazy_B1;
        i64 lazy_revB1;

        i64 lazy_B2;
        i64 lazy_revB2;
    };
    std::vector<T> w;
    std::vector<node> t;

    Segt() {}
    Segt(int n) { init(n); }
    Segt(std::vector<i64> in) {
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
            t[k].l = l; t[k].r = r; t[k].lazy = 0;
            t[k].lazy_B1 = t[k].lazy_revB1 = t[k].lazy_B2 = t[k].lazy_revB2 = 1;
            if (l == r) {

                t[k].w = w[l];
                t[k].h1 = qpow(B1, w[l], M1);
                t[k].rev_h1 = qpow(inv_B1, w[l], M1);
                t[k].h2 = qpow(B2, w[l], M2);
                t[k].rev_h2 = qpow(inv_B2, w[l], M2);

                return;
            }

            int mid = (l + r) / 2;
            self(self, l, mid, GL);
            self(self, mid + 1, r, GR);
            pushup(k);
            };
        build(build, 1, n);
    }
    void pushdown(node& p, T lazy, i64 B1_dif, i64 revB1_dif, i64 B2_dif, i64 revB2_dif) { /* 【在此更新下递函数】 */
        p.w += (p.r - p.l + 1) * lazy;

        p.h1 = (p.h1 * B1_dif) % M1;
        p.rev_h1 = (p.rev_h1 * revB1_dif) % M1;

        p.h2 = (p.h2 * B2_dif) % M2;
        p.rev_h2 = (p.rev_h2 * revB2_dif) % M2;

        p.lazy += lazy;

        p.lazy_B1 = p.lazy_B1 * B1_dif % M1;
        p.lazy_revB1 = p.lazy_revB1 * revB1_dif % M1;

        p.lazy_B2 = p.lazy_B2 * B2_dif % M2;
        p.lazy_revB2 = p.lazy_revB2 * revB2_dif % M2;
    }
    void pushdown(int k) {
        if (t[k].lazy == 0) return;
        pushdown(t[GL], t[k].lazy, t[k].lazy_B1, t[k].lazy_revB1, t[k].lazy_B2, t[k].lazy_revB2);
        pushdown(t[GR], t[k].lazy, t[k].lazy_B1, t[k].lazy_revB1, t[k].lazy_B2, t[k].lazy_revB2);
        t[k].lazy = 0;
        t[k].lazy_B1 = t[k].lazy_revB1 = t[k].lazy_B2 = t[k].lazy_revB2 = 1;
    }
    void pushup(int k) {
        auto pushup = [&](node& p, node& l, node& r) { /* 【在此更新上传函数】 */
            p.w = l.w + r.w;

            p.h1 = (l.h1 + r.h1) % M1;
            p.rev_h1 = (l.rev_h1 + r.rev_h1) % M1;

            p.h2 = (l.h2 + r.h2) % M2;
            p.rev_h2 = (l.rev_h2 + r.rev_h2) % M2;
            };
        pushup(t[k], t[GL], t[GR]);
    }
    void modify(int l, int r, T val, i64 B1_dif, i64 revB1_dif, i64 B2_dif, i64 revB2_dif, int k = 1) { // 区间修改
        if (l <= t[k].l && t[k].r <= r) {
            pushdown(t[k], val, B1_dif, revB1_dif, B2_dif, revB2_dif);
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        if (l <= mid) modify(l, r, val, B1_dif, revB1_dif, B2_dif, revB2_dif, GL);
        if (mid < r) modify(l, r, val, B1_dif, revB1_dif, B2_dif, revB2_dif, GR);
        pushup(k);
    }
    node ask(int l, int r, int k = 1) { // 区间询问
        if (l <= t[k].l && t[k].r <= r) {
            return t[k];
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;

        int left = 0, right = 0;

        if (l <= mid) left = 1;
        if (r > mid) right = 1;

        if (left && !right) return ask(l, r, GL);
        if (!left && right) return ask(l, r, GR);

        node ans;
        node res1 = ask(l, r, GL);
        node res2 = ask(l, r, GR);

        ans.w = res1.w + res2.w;

        ans.h1 = (res1.h1 + res2.h1) % M1;
        ans.rev_h1 = (res1.rev_h1 + res2.rev_h1) % M1;

        ans.h2 = (res1.h2 + res2.h2) % M2;
        ans.rev_h2 = (res1.rev_h2 + res2.rev_h2) % M2;

        return ans;
    }
};

void solve()
{
    int n, q;   std::cin >> n >> q;
    std::vector<i64> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];
    Segt<i64> tr(a);

    while (q--) {
        int op;     std::cin >> op;
        if (op == 1) {
            int l, r, v;    std::cin >> l >> r >> v;
            i64 B1_dif = qpow(B1, v, M1);
            i64 revB1_dif = qpow(inv_B1, v, M1);
            i64 B2_dif = qpow(B2, v, M2);
            i64 revB2_dif = qpow(inv_B2, v, M2);
            tr.modify(l, r, v, B1_dif, revB1_dif, B2_dif, revB2_dif);
        }
        else {
            int l, r;   std::cin >> l >> r;
            Segt<i64>::node res = tr.ask(l, r);

            i64 tmp1 = qpow(B1, res.w * 2 / (r - l + 1), M1);
            i64 tmp2 = qpow(B2, res.w * 2 / (r - l + 1), M2);

            if (res.h1 == res.rev_h1 * tmp1 % M1 && res.h2 == res.rev_h2 * tmp2 % M2)    std::cout << "YES";
            else std::cout << "NO";
            std::cout << '\n';
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
}