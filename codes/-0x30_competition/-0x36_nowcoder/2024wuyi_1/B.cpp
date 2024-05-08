#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 500, MAXN = N + 10, inf = 1e9, mod = 1e9 + 7;
i64 nums[MAXN], n, k;
using pt = std::pair<int, int>;

std::string coffee = "COFFEE";
std::string chicken = "CHICKEN";
void solve() {
    std::cin >> n >> k;
    std::string ans;
    if (n >= 58)
        n -= (n - 58) / 2 * 2;
    for (i64 pos = k;pos <= std::min(k + 9, nums[n]);++pos) {
        i64 x = pos;
        i64 i = n;
        while (i >= 3) {
            if (x > nums[i - 2]) {
                x -= nums[i - 2];
                i -= 1;
            }
            else {
                i -= 2;
            }
        }
        if (i == 1) {
            ans += coffee[x - 1];
        }
        else if (i == 2) {
            ans += chicken[x - 1];
        }
    }
    std::cout << ans;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    nums[1] = 6, nums[2] = 7;
    for (int i = 3;i <= 60;++i) {
        nums[i] = nums[i - 2] + nums[i - 1];
    }
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}