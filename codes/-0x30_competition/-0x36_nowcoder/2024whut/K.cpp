#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> fa[n + 1];
    std::vector<i64> sum(n + 1);
    for (int i = 1;i <= n;++i) {
        int k;std::cin >> k;
        while (k--) {
            int f;std::cin >> f;
            sum[i] += sum[f];
            sum[i] = std::min(sum[i], (i64)1e15);
            fa[i].push_back(f);
        }
        sum[i]++;
    }
    std::function<int(int, i64)> dfs = [&](int n, i64 m)->int {
        if (sum[n] == m)return n;
        i64 cur = 0;
        for (auto x : fa[n]) {
            if (cur + sum[x] >= m) {
                return dfs(x, m - cur);
            }
            cur += sum[x];
        }
        return 0;
        };
    i64 m;std::cin >> m;
    std::cout << dfs(n, m);
    return 0;
}