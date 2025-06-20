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
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    a.insert(a.end(), a.begin(), a.end());
    // for (auto x : a)std::cout << x << ' ';
    std::vector<int> res(n);
    res.back() = 1;
    for (int i = 0;i < n;++i) {
        for (int j = i + 1;j < i + n;++j) {
            if (a[j - 1] == a[j]) {
                break;
            }
            else if (a[i] != a[j]) {
                // if (n - (j - i + 1) == 0)std::cout << i << ' ' << j << '\n';
                res[n - (j - i + 1)] = 1;
                // if (j - i + 1 == 9) {
                //     std::cout << i << ' ' << j << '\n';
                //     for (int k = i;k <= j;++k)std::cout << a[k] << ' ';std::cout << '\n';
                // }
            }
        }
    }
    for (auto x : res)std::cout << x;
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