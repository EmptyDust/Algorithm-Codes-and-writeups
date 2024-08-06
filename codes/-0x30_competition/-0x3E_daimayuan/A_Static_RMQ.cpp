#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct sparse_table
{
    std::vector<std::vector<int>> vt;
    sparse_table(std::vector<int> a) {
        int n = a.size();
        vt.assign(n, std::vector<int>(30));
        for (int i = 0;i < n;++i)
            vt[i][0] = a[i];
        for (int s = 1;s < 30;++s) {
            for (int i = 0;i < n;++i) {
                int j = i + (1 << s - 1);
                if (j < n) {
                    vt[i][s] = std::min(vt[i][s - 1], vt[i + (1 << s - 1)][s - 1]);
                }
                else vt[i][s] = vt[i][s - 1];
            }
        }
    }
    int query(int l, int r) {//[l,r)
        int len = r - l;
        int x = std::__lg(len);
        return std::min(vt[l][x], vt[r - (1 << x)][x]);
    }
};


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    sparse_table st(a);
    while (q--) {
        int l, r;std::cin >> l >> r;
        std::cout << st.query(l, r) << '\n';
    }
    return 0;
}