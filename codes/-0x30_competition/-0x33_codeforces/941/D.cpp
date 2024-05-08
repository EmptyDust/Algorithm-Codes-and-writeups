#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

std::vector<int> ans;
void solve() {
    ans.clear();
    i64 n, k;std::cin >> n >> k;
    i64 sum = 0;
    while (sum + sum + 1 < k) {
        ans.push_back(sum + 1);
        sum = sum * 2 + 1;
    }
    if (k - sum - 1 > 0)
        ans.push_back(k - sum - 1);
    if (k == n)return;
    ans.push_back(k + 1);
    sum = 2 * k;
    if (sum >= n)return;
    ans.push_back(2 * k + 1);
    sum += k;
    if (sum >= n)return;
    while (sum < n) {
        ans.push_back(sum - k);
        sum += sum - k;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << ans.size() << '\n';
        for (int x : ans)std::cout << x << ' ';
        std::cout << '\n';
    }
    return 0;
}