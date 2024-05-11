#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 200010, mod = 1e9 + 7;
const int inf = 1e15;
int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) res = res * a % mod;
    }
    return res;
}
template <typename T, typename F>
struct segtree {
#define ls (x << 1)
#define rs (x << 1 | 1)
#define mid (pl + pr >> 1)

    vector<T> tr;
    vector<T> d;
    vector<F> tag;
    vector<bool> istag;
    int n;

    void init() {
        tr.resize(n * 4);
        tag.resize(n * 4);
        istag.resize(n * 4);
        build(1, 1, n);
    }

    segtree(int _n) :n(_n) {
        d.assign(n, T());
        init();
    }

    segtree(int _n, T* a) :n(_n) {
        d.resize(n);
        for (int i = 0; i < n; i++) d[i] = a[i];
        init();
    }

    segtree(int _n, vector<T>& a) :n(_n) {
        d.resize(n);
        for (int i = 0; i < n;i++) d[i] = a[i];
        init();
    }

    void build(int x, int pl, int pr) {
        tag[x] = F();
        if (pl == pr) {
            tr[x] = d[pl - 1];
            return;
        }
        build(ls, pl, mid);
        build(rs, mid + 1, pr);
        push_up(x);
    }

    inline void add_tag(int x, F& val) {
        istag[x] = true;
        tr[x] = tr[x] + val;
        tag[x] = tag[x] + val;
    }

    inline void push_down(int x) {
        if (!istag[x]) return;
        add_tag(ls, tag[x]);
        add_tag(rs, tag[x]);
        tag[x] = F();
        istag[x] = false;
    }

    inline void push_up(int x) {
        tr[x] = tr[ls] + tr[rs];
    }

    void modify(int x, F val) { modify(1, 1, n, x, x, val); }
    void modify(int l, int r, F val) { modify(1, 1, n, l, r, val); }
    void modify(int x, int pl, int pr, int l, int r, F val) {
        if (pl >= l && pr <= r) {
            add_tag(x, val);
            return;
        }
        push_down(x);
        if (l <= mid) modify(ls, pl, mid, l, r, val);
        if (r > mid) modify(rs, mid + 1, pr, l, r, val);
        push_up(x);
    }

    T query(int x) { return query(1, 1, n, x, x); }
    T query(int l, int r) { return query(1, 1, n, l, r); }
    T query(int x, int pl, int pr, int l, int r) {
        if (pl >= l && pr <= r) {
            return tr[x];
        }
        push_down(x);
        if (r <= mid) return query(ls, pl, mid, l, r);
        if (l > mid) return query(rs, mid + 1, pr, l, r);
        return query(ls, pl, mid, l, r) + query(rs, mid + 1, pr, l, r);
    }

    // 若区间范围为 [l,r] ,存在分段点 p 满足 [l,p) 的前缀代入函数为false, [p,r] 代入为true, 返回下标 p
    template<class FU> int lower_bound(FU&& f) { return lower_bound(1, n, f); }
    template<class FU> int lower_bound(int l, FU&& f) { return lower_bound(l, n, f); }
    template<class FU> int lower_bound(int l, int r, FU&& f) {
        T cur = T();
        auto nlb = [&](auto self, int x, int pl, int pr, int l, int r) {
            // cout << " now_node " << x << ' ' << pl << " " << pr << " " << l << " " << r << endl;
            if (pl >= l && pr <= r) {
                // 如果当前区间已经整个在待查询区间内，则测试加上此区间是否为 false ,若为 false ,则直接返回 ,若为 true 则答案就在此区间。
                if (!f(cur + tr[x])) {
                    cur = cur + tr[x];
                    return pr + 1;
                }
                if (pl == pr) return pl;
            }

            push_down(x);
            if (l <= mid) {
                int la = self(self, ls, pl, mid, l, r);
                if (la != mid + 1) return la;
            }
            if (r > mid) {
                int lb = self(self, rs, mid + 1, pr, l, r);
                return lb;
            }
            return mid + 1;
            };

        int p = nlb(nlb, 1, 1, n, l, r);
        return p;
    }

#undef ls
#undef rs
#undef mid
};

struct lazy_tag {
    int add;
    lazy_tag() : add(0) {}
    lazy_tag(int a) : add(a) {}

    lazy_tag operator +(lazy_tag& a) {
        auto res = *this;
        if (a.add) res.add += a.add;
        return res;
    }
};
struct node {
    int sum, len;
    node() : sum(0), len(0) {}
    node(int a, int b) : sum(a), len(b) {}

    node operator +(const node& a) {
        node res = *this;
        res.sum = a.sum + sum;
        res.len = a.len + len;
        return res;
    }

    node operator +(const lazy_tag& a) {
        node res = *this;
        if (a.add) res.sum += a.add * len;
        return res;
    }
};

using tree = segtree<node, lazy_tag>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<node> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = { x, 1 };
    }
    tree tr(n, a);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            tr.modify(l, r, k);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << tr.query(l, r).sum << endl;
        }
    }
}
signed main() {
    //freopen("title.in", "r", stdin);
    //freopen("title.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}