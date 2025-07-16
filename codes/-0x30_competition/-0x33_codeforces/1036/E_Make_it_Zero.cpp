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
    std::vector<i64> a(n), b(n);
    for (auto& x : a)std::cin >> x;
    if (std::accumulate(a.begin(), a.end(), 0ll) % 2) {
        std::cout << -1;
        return;
    }
    if (ranges::max(a) * 2 > std::accumulate(a.begin(), a.end(), 0ll)) {
        std::cout << -1;
        return;
    }
    i64 sum0 = 0, sum1 = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (sum0 <= sum1) {
            sum0 += a[i];
            i++;
        }
        else {
            sum1 += a[j];
            j--;
        }
    }
    if (sum0 == sum1) {
        std::cout << 1 << '\n';
        for (auto x : a)std::cout << x << ' ';
        return;
    }
    // std::cout << sum0 << ' ' << sum1 << '\n';
    i64 d = std::abs(sum0 - sum1) / 2;
    std::cout << 2 << '\n';
    if (sum0 > sum1) {
        int p = j;
        b[p] = d;
        for (int i = 0;i < n;++i) {
            if (a[i] >= d) {
                b[i] = d;
                break;
            }
            b[i] = a[i];
            d -= a[i];
        }
    }
    else {
        int p = i;
        b[p] = d;
        for (int i = n - 1;i >= 0;--i) {
            if (a[i] >= d) {
                b[i] = d;
                break;
            }
            b[i] = a[i];
            d -= a[i];
        }
    }
    for (int i = 0;i < n;++i) {
        std::cout << b[i] << ' ';
        a[i] -= b[i];
    }
    std::cout << '\n';
    for (auto x : a)std::cout << x << ' ';
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