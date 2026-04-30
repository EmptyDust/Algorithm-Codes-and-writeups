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

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

struct Info
{
    int cnt0 = 0;
    int cnt1 = 0;
    int max0 = -1;
    int max1 = -1;
    Info(int x, int p) {
        if (p % 2)cnt1++, max1 = x;
        else cnt0++, max0 = x;
    }
    void operator+=(const Info a) {
        cnt0 += a.cnt0;
        cnt1 += a.cnt1;
        max0 = std::max(max0, a.max0);
        max1 = std::max(max1, a.max1);
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), zbs(n), sel(n);
    auto get = [&](int x) {
        if (x < 0 || x >= n)return 0;
        return sel[x];
        };
    for (int& x : a)std::cin >> x;
    std::iota(zbs.begin(), zbs.end(), 0);
    ranges::sort(zbs, [&](int x, int y) {return a[x] > a[y];});
    std::vector<Info> info;info.reserve(n);
    for (int i = 0;i < n;++i)info.push_back(Info(a[i], i));
    dsu d(n);
    int cnt = 0, max = a[zbs[0]], cur = 0;
    auto add = [&](int x) {
        if (info[x].max0 == max && info[x].cnt0 >= info[x].cnt1)cnt++;
        if (info[x].max1 == max && info[x].cnt1 >= info[x].cnt0)cnt++;
        cur += std::max(info[x].cnt0, info[x].cnt1);
        };
    auto del = [&](int x) {
        if (info[x].max0 == max && info[x].cnt0 >= info[x].cnt1)cnt--;
        if (info[x].max1 == max && info[x].cnt1 >= info[x].cnt0)cnt--;
        cur -= std::max(info[x].cnt0, info[x].cnt1);
        };
    int ans = 0;
    for (int p : zbs) {
        int M = a[p];
        if (get(p - 1)) {
            if (sel[p])del(p);
            del(d.get_root(p - 1));
            sel[p] = 1;
            info[p] += info[d.get_root(p - 1)];
            add(p);
            d.merge(p - 1, p);
        }
        // if (p == 3)std::cout << cur << ' ';
        if (get(p + 1)) {
            if (sel[p])del(p);
            del(d.get_root(p + 1));
            sel[p] = 1;
            info[p] += info[d.get_root(p + 1)];
            add(p);
            d.merge(p + 1, p);
        }
        if (!sel[p]) {
            cur++;
            if (a[p] == max) cnt++;
            sel[p] = 1;
        }
        ans = std::max(ans, max + M + cur - (cnt == 0));
        // std::cout << p << ' ' << cur << ' ' << M << ' ' << cnt << '\n';
    }
    std::cout << ans;
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