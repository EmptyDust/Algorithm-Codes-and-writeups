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

struct Info
{
    int a;
    Info operator+(Info x) {
        return Info(std::gcd(a, x.a));
    }
};

struct sparse_table
{
    std::vector<std::vector<Info>> vt;
    sparse_table(std::vector<Info> a) {
        int n = a.size();
        vt.assign(n, std::vector<Info>(30));
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
    Info query(int l, int r) {//[l,r)
        int len = r - l;
        int x = std::__lg(len);
        return vt[l][x] + vt[r - (1 << x)][x];
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    std::vector<Info> _a(n), _b(n);
    for (int i = 0;i < n;++i)_a[i] = Info(a[i]);
    for (int i = 0;i < n;++i)_b[i] = Info(b[i]);
    sparse_table ast(_a), bst(_b);
    std::vector<int> apre(n), asuf(n), bpre(n), bsuf(n);
    apre[0] = a[0];
    asuf[n - 1] = a[n - 1];
    bpre[0] = b[0];
    bsuf[n - 1] = b[n - 1];
    std::vector<int> c;
    c.push_back(0);
    c.push_back(n - 1);
    for (int i = 1;i < n;++i) {
        apre[i] = std::__gcd(a[i], apre[i - 1]);
        bpre[i] = std::__gcd(b[i], bpre[i - 1]);
        if (apre[i] != apre[i - 1] || bpre[i] != bpre[i - 1])
            c.push_back(i - 1);
    }
    for (int i = n - 2;i >= 0;--i) {
        asuf[i] = std::__gcd(a[i], asuf[i + 1]);
        bsuf[i] = std::__gcd(b[i], bsuf[i + 1]);
        if (asuf[i] != asuf[i + 1] || bsuf[i] != bsuf[i + 1])
            c.push_back(i + 1);
    }
    auto gcda = [&](int l, int r) {
        int gcd = ast.query(l, r + 1).a;
        if (l)gcd = std::__gcd(apre[l - 1], gcd);
        if (r < n - 1)gcd = std::__gcd(asuf[r + 1], gcd);
        return gcd;
        };
    auto gcdb = [&](int l, int r) {
        int gcd = bst.query(l, r + 1).a;
        if (l)gcd = std::__gcd(bpre[l - 1], gcd);
        if (r < n - 1)gcd = std::__gcd(bsuf[r + 1], gcd);
        return gcd;
        };
    int ans = asuf[0] + bsuf[0];
    for (auto x : c)
        for (auto y : c)
            if (x <= y) {
                ans = std::max(ans, gcda(x, y) + gcdb(x, y));
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