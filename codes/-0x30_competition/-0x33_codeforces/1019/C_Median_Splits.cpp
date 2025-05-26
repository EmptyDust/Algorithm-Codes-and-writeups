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
    std::vector<int> a(n), pre(n), suf(n);
    for (auto& x : a)std::cin >> x;
    int p = 0, res = 0;
    int p1 = inf;
    for (int i = 0;i < n - 1;++i) {
        if (a[i] <= k)p++;
        else p--;
        if (a[i] <= k && p >= 0) {
            res++;
        }
        if (p >= 0 && p1 == inf)p1 = i;
        if (p >= 2 || res >= 2) {
            std::cout << "YES";
            return;
        }
    }
    p = 0;
    res = 0;
    for (int i = n - 1;i >= 1;--i) {
        if (a[i] <= k)p++;
        else p--;
        if (a[i] <= k && p >= 0) {
            res++;
        }
        if (p >= 0 && i > p1 + 1) {
            std::cout << "YES";
            return;
        }
        if (p >= 2 || res >= 2) {
            std::cout << "YES";
            return;
        }
    }
    std::cout << "NO";
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