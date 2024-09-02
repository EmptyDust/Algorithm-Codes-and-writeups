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

int n, q;
struct Lazy
{
    int x = 0;
    Lazy operator+ (const Lazy& l) {
        return Lazy(x ^ l.x);
    }
}lazy[MAXN << 2];

struct Info {
    bool same = 1;
    int x = -1;
    Info operator+ (const Info& x) {
        if (this->x == -1)return x;
        if (x.x == -1)return *this;
        Info res = Info();
        res.same = same & x.same & (this->x == x.x);
        res.x = x.x;
        return res;
    }
    Info operator+ (const Lazy& l) {
        return Info(same, x ^ l.x);
    }
}tree[MAXN << 2];

void push_down(int x) {
    tree[x << 1] = tree[x << 1] + lazy[x];
    tree[x << 1 | 1] = tree[x << 1 | 1] + lazy[x];
    lazy[x << 1] = lazy[x << 1] + lazy[x];
    lazy[x << 1 | 1] = lazy[x << 1 | 1] + lazy[x];
    lazy[x] = Lazy();
}

void push_up(int x) {
    tree[x] = tree[x << 1] + tree[x << 1 | 1];
}

void update(int p, Info x, int l = 1, int r = n, int i = 1) {
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

i64 query(int ql, int qr, int x, int l = 1, int r = n, int i = 1) {
    // std::cout << l << ' ' << mid << " " << r << '\n';
    if (l > r) return 0;
    if (qr < l || r < ql)return 0;
    if (ql <= l && r <= qr && tree[i].same) {
        if (tree[i].x != x)return 0;
        tree[i] = tree[i] + Lazy(1);
        lazy[i] = lazy[i] + Lazy(1);
        return r - l + 1;
    }
    push_down(i);
    int mid = l + r >> 1;
    int ret = query(ql, qr, x, l, mid, i << 1) + query(ql, qr, x, mid + 1, r, i << 1 | 1);;
    push_up(i);
    return ret;
}

void solve() {
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
        update(i, Info(1, a[i] & 1));
    }
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    std::cout << query(2, 4, 0) << '\n';
    std::cout << query(3, 3, 0) << '\n';
    // i64 res = 0;
    // for (int i = 1;i <= q;++i) {
    //     int l, r, c;std::cin >> l >> r >> c;
    //     sum -= query(l, r, c);
    //     res ^= i * sum;
    //     std::cout << sum << ' ';
    // }
    // std::cout << res;
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