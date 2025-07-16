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
    int n, x;std::cin >> n >> x;x--;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    if (n <= 2) {
        std::sort(a.begin(), a.end());
        std::cout << a.back();
        return;
    }
    std::vector<int> b;
    if (x)b.push_back(a[x - 1]);
    if (x < n - 1)b.push_back(a[x + 1]);
    b.push_back(a[x]);
    std::sort(b.begin(), b.end(), std::greater<int>());
    int ans = b[1];
    std::sort(a.begin(), a.end());
    ans = std::max(ans, a[2]);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}