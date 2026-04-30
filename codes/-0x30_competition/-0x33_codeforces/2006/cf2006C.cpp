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
        int len = r - l + 1;
        int x = std::__lg(len);
        return vt[l][x] + vt[r - (1 << x) + 1][x];
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), lst(n);
    std::vector<Info> b(n - 1);
    for (auto& x : a)std::cin >> x;
    lst[n - 1] = n - 1;
    for (int i = n - 2;i >= 0;--i)lst[i] = (a[i] == a[i + 1] ? lst[i + 1] : i);
    for (int i = 0;i < n - 1;++i)b[i].a = a[i + 1] - a[i];
    sparse_table st(b);
    // std::cout << std::__popcount(st.query(0, 0).a) << "\n";
    i64 ans = 1;
    for (int l = 0, r = 0, i = 0;i < n - 1;++i) {
        l = std::max(l, lst[i]);
        r = std::max(l, r);
        while (r < n - 1 && std::__popcount(st.query(i, r).a) != 1)
            r++;
        ans += n - 1 - r;
        ans += lst[i] - i + 1;
        // ans++;
        // // if (l != i + 1)ans++;
        // std::cout << i << ' ' << l << " " << r << ' ' << ans << '\n';
        // std::cout << ans << ' ';
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