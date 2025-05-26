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

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector left(k, std::vector<int>(n));
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < k;++j) {
            left[j][i] = (a[i] >> j & 1) ? i : i ? left[j][i - 1] : -1;
        }
        // std::cout << ((a[i] >> 1 & 1) ? i : i ? left[1][i - 1] : -1) << ' ';
    }
    auto get = [&](int l, int r) {
        int res = 0;
        for (int i = 0;i < k;++i) {
            int f = 0;
            int j = left[i][r];
            if (l < j) {
                f = (r - j) & 1;
            }
            else if (l == j) {
                f = (r - j + 1) & 1;
            }
            else {
                f = (r - l) & 1;
            }
            if (f) res |= 1 << i;
        }
        return res;
        };

    std::vector add(n + 1, std::vector<int>()), del(n + 1, std::vector<int>());
    for (int r = 0;r < n;++r) {
        std::vector<int> p;
        for (int i = 0;i < k;++i) {
            int L = left[i][r];
            for (int j : { L, L + 1, L + 2 }) {
                if (j < 0 || j > r)continue;
                p.push_back(j);
            }
        }
        for (int j = 0;j <= 2;++j) {
            if (j < 0 || j > r)continue;
            p.push_back(j);
        }
        std::sort(p.begin(), p.end());
        p.erase(std::unique(p.begin(), p.end()), p.end());
        for (auto l : p) {
            int res = get(l, r);
            add[l].push_back(res);
            del[r].push_back(res);
        }
    }

    std::multiset<int> in;
    for (int i = 0;i < n;++i) {
        for (auto x : add[i])in.insert(x);
        std::cout << *in.rbegin() << ' ';
        for (auto x : del[i])in.extract(x);
    }

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