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
        if (l >= r) return Info(0);
        int len = r - l;
        int x = std::__lg(len);
        return vt[l][x] + vt[r - (1 << x)][x];
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    if (std::count(a.begin(), a.end(), a[0]) == n) {
        std::cout << 0;
        return;
    }
    std::vector<Info> A(n);
    for (int i = 1;i < n;++i)A[i] = Info(a[i] - a[i - 1]);
    sparse_table st(A);
    auto suf(a), pre(a);
    std::vector<int> last;
    for (int i = n - 2;i >= 0;--i) {
        suf[i] = std::__gcd(suf[i], suf[i + 1]);
        if (suf[i] != suf[i + 1]) last.push_back(i + 1);
    }
    for (int i = 1;i < n;++i) {
        pre[i] = std::__gcd(pre[i], pre[i - 1]);
    }
    int ans = st.query(0, n).a;
    for (int i = 0;i < n;++i) {
        ans = std::max(ans, std::__gcd(suf[i], st.query(0, i).a));
    }
    for (int i = n - 1;i >= 0;--i) {
        ans = std::max(ans, std::__gcd(pre[i], st.query(i + 2, n).a));
    }
    for (int i = 1;i < n - 1;++i) {
        ans = std::max(ans, std::__gcd(pre[i - 1], suf[i + 1]));
    }
    for (int i = 0;i < n;++i) {
        for (int j : last) if (j > i + 2) {
            int res = std::__gcd(pre[i], suf[j]);
            res = std::__gcd(res, st.query(i + 2, j).a);
            ans = std::max(ans, res);
        }
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