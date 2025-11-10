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

struct Info
{
    i64 a;
    Info operator+(Info x) {
        return Info(std::max(a, x.a));
    }
};

template<class T>
struct sparse_table
{
    std::vector<std::vector<T>> vt;
    sparse_table(std::vector<T> a) {
        int n = a.size();
        vt.assign(n, std::vector<T>(30));
        for (int i = 0;i < n;++i)
            vt[i][0] = a[i];
        for (int s = 1;s < 30;++s) {
            for (int i = 0;i < n;++i) {
                int j = i + (1 << s - 1);
                if (j < n) {
                    vt[i][s] = vt[i][s - 1] + vt[i + (1 << s - 1)][s - 1];
                }
                else vt[i][s] = vt[i][s - 1];
            }
        }
    }
    T query(int l, int r) {//[l,r)
        if (l == r) return T(0);
        int len = r - l;
        int x = std::__lg(len);
        return vt[l][x] + vt[r - (1 << x)][x];
    }
};

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector<Info> pb(n), sb(n);
    std::vector<i64> c(n), prefc(n), d(n);
    std::set<int> pos;
    for (i64 i = 0, pre = 0;i < n;++i) {
        if (pre + a[i] <= 0) {
            c[i] = -(pre + a[i]);
            pre = 0;
            pos.insert(i);
        }
        else pre += a[i];
        prefc[i] = c[i];
        if (i)prefc[i] += prefc[i - 1];
        pb[i].a = pre;
    }
    ranges::reverse(a);
    for (i64 i = 0, pre = 0;i < n;++i) {
        if (pre + a[i] < 0) {
            d[i] = -(pre + a[i]);
            pre = 0;
        }
        else pre += a[i];
        sb[i].a = pre;
    }
    ranges::reverse(a);
    ranges::reverse(sb);
    ranges::reverse(d);
    sparse_table<Info> stpb(pb), stsb(sb);
    while (q--) {
        int l, r;std::cin >> l >> r; l--;
        if (l > 0 && c[l - 1] == 0 || r < n && d[r] == 0) {
            std::cout << -1 << '\n';
            continue;
        }
        i64 cost = prefc[r - 1] - (l ? prefc[l - 1] : 0);
        i64 last = pb[r - 1].a;
        i64 max = std::max(stpb.query(0, l).a, stsb.query(r, n).a);
        auto it = pos.lower_bound(l);
        int fpos = (it == pos.end() || r <= (*it)) ? -1 : (*it);
        if (fpos == -1) {
            max = std::max(max, stpb.query(l, r - 1).a);
        }
        else {
            max = std::max(max, stpb.query(l, fpos).a);
            if (fpos != r - 1) max = std::max(max, stpb.query(fpos, r - 1).a + 1);
            cost++;
            last++;
        }
        if (last <= max) cost += max + 1 - last;
        std::cout << cost << '\n';
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
