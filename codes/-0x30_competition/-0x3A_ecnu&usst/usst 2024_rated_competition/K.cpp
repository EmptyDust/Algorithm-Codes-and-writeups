#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::sort(a.begin(), a.end());
    int cur = -1;
    for (int i = 0;i < n;++i) {
        if (a[i] == cur)continue;
        int len = a[i] - cur - 1;
        if (len < k) {
            k -= len;
            cur = a[i];
        }
        else {
            cur += k;
            std::cout << cur;
            return 0;
        }
    }
    std::cout << cur + k;
    return 0;
}