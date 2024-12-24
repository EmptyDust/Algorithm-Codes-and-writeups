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
    int n, x, y;std::cin >> n >> x >> y;
    x--, y--;
    std::vector<int> ans(n, -1);
    ans[x] = 0, ans[y] = 1;
    for (int i = 0;i < n;++i) if (ans[i] == -1) {
        int up = ans[(i + 1) % n];
        int down = ans[(i - 1 + n) % n];
        std::vector<int> arr(5, 0);
        if (up != -1)arr[up] = 1;
        if (down != -1)arr[down] = 1;
        for (int x = 0;x < 5;++x)if (!arr[x]) {
            ans[i] = x;
            break;
        }
    }
    for (int i = 0;i < n;++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}