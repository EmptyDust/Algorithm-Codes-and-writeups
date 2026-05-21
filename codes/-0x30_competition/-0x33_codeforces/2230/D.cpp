#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

#define int i64

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1), next(n + 2, 0), end(n + 2, 0);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    std::map<int, int> notvaildpos;
    std::iota(end.begin(), end.end(), 0);
    for (int i = 1; i <= n + 1; ++i)
        notvaildpos[i] = n + 1;

    for (int i = n; i >= 1; --i) {
        int x = a[i], y = b[i];
        if (x != y) {
            notvaildpos[x] = i;
            notvaildpos[y] = i;
        } else {
            next[i] = notvaildpos[x] = notvaildpos[x + 1];
            if (x == 1) {
                end[i] = next[i];
            }
        }
        if (x != 1 && y != 1)
            end[i] = std::max(i + 1, end[i + 1]);
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        // std::cout << end[i] << ' ';
        ans += end[i] - i;
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}