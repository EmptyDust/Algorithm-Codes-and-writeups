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
        return Info(std::min(a, x.a));
    }
    Info() {
        a = 0;
    }
    Info(int x) {
        a = x;
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
    int n, q;std::cin >> n >> q;
    std::vector<Info> cnt(n + 1);
    std::vector<a3> query(q);
    for (auto& [l, r, x] : query)std::cin >> l >> r >> x, cnt[l - 1].a++, cnt[r].a--, l--;
    for (int i = 1;i <= n;++i)cnt[i].a += cnt[i - 1].a;
    // for (auto x : cnt)std::cout << x.a << ' ';std::cout << '\n';
    sparse_table st(cnt);
    std::vector<a3> vt(q);
    for (int i = 0;i < q;++i) {
        vt[i][0] = st.query(query[i][0], query[i][1]).a;
        vt[i][1] = query[i][0] - query[i][1];
        vt[i][2] = i;
        // std::cout << i << ' ' << vt[i][1] << '\n';
    }
    std::sort(vt.begin(), vt.end(), std::greater<a3>());
    std::vector<int> ans(n, -1);
    for (auto [_, __, pos] : vt) {
        // std::cout << pos << ' ';
        auto [l, r, x] = query[pos];
        int p = -1, res = 0;
        for (int i = l;i < r;++i) {
            if (ans[i] == -1) {
                if (p == -1)p = i;
                else ans[i] = 0;
            }
            else res ^= ans[i];
        }
        if (p == -1 && x != res) {
            std::cout << -1;
            return;
        }
        if (p != -1) ans[p] = res ^ x;
        // for (auto x : ans)std::cout << x << " ";std::cout << '\n';
    }
    for (auto& x : ans)if (x == -1)x = 114514;
    for (auto x : ans)std::cout << x << ' ';
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