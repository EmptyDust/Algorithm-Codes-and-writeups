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

void solve() {
    int n;std::cin >> n;
    std::vector<int> v(1 << n), p;
    for (int i = 1;i < (1 << n);++i)std::cin >> v[i];
    std::vector<bool> ok(1 << n, 1);
    std::vector zi(1 << n, std::vector<int>());
    std::vector chao(1 << n, std::vector<int>());

    for (int s = 0;s < (1 << n);++s)zi[s].push_back(s);
    for (int s = 0;s < (1 << n);++s)chao[s].push_back(s);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < 1 << n; i++)
            if (i >> j & 1)
                for (int& x : zi[i ^ (1 << j)]) {
                    zi[i].push_back(x);
                }
    for (int j = 0; j < n; j++)
        for (int i = 0; i < 1 << n; i++)
            if (!(i >> j & 1))
                for (int& x : chao[i ^ (1 << j)]) {
                    chao[i].push_back(x);
                }



    for (int s = 1;s < (1 << n);++s) {
        for (int i = 0;i <= n;++i) {
            if (!(v[s] >> i & 1)) {
                
            }
        }
    }









    for (auto x : chao[19])std::cout << x << " ";
    for (int s = (1 << n) - 1;s >= 1;--s) {
        for (int x : zi[s])if (ok[x]) {
            if (!((1 << std::__popcount(s & x)) & v[s])) {
                // std::cout << x << ' ';
                ok[x] = false;
            }
            // std::cout << s << '\n';
        }
        if (v[s] % 2 == 0)
            for (int x : chao[s])if (ok[x] && x != s) {
                ok[x] = false;
            }
    }

    std::cout << std::count(ok.begin(), ok.end(), 1) << "\n";
    for (int s = 0;s < (1 << n);++s)
        if (ok[s])
            std::cout << s << '\n';
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