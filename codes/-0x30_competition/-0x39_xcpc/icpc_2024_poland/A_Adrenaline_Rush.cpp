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
    std::vector<int> a(n), b(n);
    for (int& x : a)std::cin >> x;
    std::iota(b.begin(), b.end(), 1);
    std::vector<pii> ans;
    for (int i = n - 1;i >= 0;--i) {
        int p = -1;
        for (int j = 0;j < n;++j)if (b[j] == a[i]) {
            p = j;
            break;
        }
        for (;p > 0;--p) {
            ans.push_back({ b[p],b[p - 1] });
            std::swap(b[p], b[p - 1]);
        }
        for (int j = 1;j <= i;++j) {
            ans.push_back({ b[j],b[j - 1] });
            std::swap(b[j], b[j - 1]);
        }
    }
    // for (int x : b)std::cout << x << ' ';
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans)std::cout << x << ' ' << y << '\n';
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