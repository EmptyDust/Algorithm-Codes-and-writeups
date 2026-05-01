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

struct Info {
    std::array<pii, 9> io;
    Info() {
        for (int i = 0;i < 9;++i)io[i] = { inf,inf };
    }
    Info(int x) {
        int _x = x;
        for (int i = 0;i < 9;++i) {
            if (x % 10)io[i] = { _x,inf };
            else io[i] = { inf,inf };
            x /= 10;
        }
    }
};
inline Info operator+(Info a, Info b) {
    Info c;
    for (int i = 0;i < 9;++i) {
        c.io[i].first = std::min(a.io[i].first, b.io[i].first);
        if (a.io[i].first < b.io[i].first) {
            c.io[i].second = std::min(b.io[i].first, a.io[i].second);
        }
        else {
            c.io[i].second = std::min(a.io[i].first, b.io[i].second);
        }
    }
    return c;
}

class SegTree {
private:
    int sz;
    std::vector<Info> a;
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return a[p];
        }
        return query(p * 2, l, (l + r) / 2, x, y) + query(p * 2 + 1, (l + r) / 2, r, x, y);
    }
public:
    SegTree(int n) {
        sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        a.resize(sz * 2);
    }
    void modify(int x, Info& y) {
        a[x + sz] = y;
        for (int i = (x + sz) / 2;i != 0;i /= 2) {
            a[i] = a[i * 2] + a[i * 2 + 1];
        }
    }
    Info query(int l, int r) {
        return query(1, 0, sz, l, r);
    }
};


void solve() {
    int n, m;std::cin >> n >> m;
    SegTree sgt(n);
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        Info c(x);
        sgt.modify(i, c);
        // for (auto [x, _] : a[i].io)std::cout << x << ' ';std::cout << std::endl;
    }
    // Info xi;xi.io = cal(310);
    // sgt.modify(0, xi);
    // auto rs = sgt.rangeQuery(0, n);
    // for (auto [x, y] : rs.io)std::cout << x << ' ' << y << '\n';//std::cout << std::endl;
    while (m--) {
        int op;std::cin >> op;
        if (op == 2) {
            int l, r;std::cin >> l >> r;l--;
            int ans = 2 * inf;
            auto p = sgt.query(l, r).io;
            for (int i = 0;i < 9;++i) {
                auto [x, y] = p[i];
                if (x != inf && y != inf)
                    ans = std::min(ans, x + y);
            }
            if (ans == 2 * inf)std::cout << -1 << '\n';
            else std::cout << ans << '\n';
        }
        else {
            int p, x;std::cin >> p >> x;p--;
            Info c(x);
            sgt.modify(p, c);
        }
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