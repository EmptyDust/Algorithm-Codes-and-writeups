#include<bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;
    while (t--) {
        int n, x, y, s;
        std::cin >> n >> x >> y >> s;
        long long st = x / y;
        if (s < 1ll * (x % y) * n) {
            std::cout << "NO\n";
            continue;
        }
        s -= (x % y) * n;
        std::vector<int> dp(s + 1, 1e9);
        std::vector<int> par(s + 1, -1);
        dp[0] = 0;
        for (int i = 0; i <= s; ++i) {
            for (int j = 1; i + j * (j - 1) / 2 * y <= s; ++j) {
                int k = i + j * (j - 1) / 2 * y;
                if (dp[k] > dp[i] + j) {
                    dp[k] = dp[i] + j;
                    par[k] = j;
                }
            }
        }
        bool ok = false;
        for (int d = 1; (2 * st + d - 1) * d / 2 * y <= s; ++d) {
            if (d + dp[s - (2 * st + d - 1) * d / 2 * y] <= n) {
                std::cout << "YES\n";
                std::vector<int> ans(n, x % y);
                int ptr = 0;
                for (int i = 0; i < d; ++i, ++ptr) ans[ptr] += (st + i) * y;
                int u = s - (2 * st + d - 1) * d / 2 * y;
                while (u != 0) {
                    int k = par[u];
                    u -= k * (k - 1) / 2 * y;
                    for (int i = 0; i < k; ++i, ++ptr) ans[ptr] += i * y;
                }
                for (auto i : ans) std::cout << i << ' ';
                std::cout << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) std::cout << "NO\n";
    }
}