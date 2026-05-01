#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::vector<bool> prime(n + 1, true);
    std::vector<int> ans;
    for (int i = 2;i <= n;++i)if (prime[i]) {
        for (int j = i;j <= n;j *= i) {
            ans.push_back(j);
        }
        for (int j = i;j <= n;j += i) if (prime[j]) {
            prime[j] = false;
        }
    }
    std::cout << ans.size() << '\n';
    for (int x : ans)std::cout << x << ' ';
    return 0;
}