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
    std::vector<Info> a(n + 1);
    std::vector<i64> b(n + 1), p(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i].a;
    for (int i = 1;i <= n;++i)std::cin >> b[i];
    for (int i = 1;i <= n;++i)p[i] = p[i - 1] + b[i];
    sparse_table st(a);
    i64 ans = 0;
    for (int i = 1;i <= n;++i) {
        auto l = i, r = n + 1;
        auto check = [&](auto x)->bool {
            return st.query(i, x + 1).a <= p[x] - p[i - 1];
            };
        while (l < r) {
            auto mid = l + r >> 1;
            if (check(mid))r = mid;
            else l = mid + 1;
        }
        ans += n - l + 1;
        // std::cout << ans << ' ';
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