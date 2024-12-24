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

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (int& x : a) x = rng();
    ranges::sort(a);
    for (int& x : a)std::cout << x << " ";std::cout << '\n';
    int p = std::partition_point(a.begin(), a.end(), [&](int x) {return x < k;}) - a.begin();
    std::cout << a[p];
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