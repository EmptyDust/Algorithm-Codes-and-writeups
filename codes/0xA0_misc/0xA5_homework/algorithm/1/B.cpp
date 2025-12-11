#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using d64 = long double;

using StateKey = std::tuple<int, std::vector<int>, std::vector<int>>;

int n, m, d;
std::map<StateKey, d64> memory;

d64 dfs(int step, std::vector<int> a, std::vector<int> b) {
    if (b.empty()) return 1.0;
    if (step == d) return 0.0;
    if (memory.count({ step, a, b })) return memory[{step, a, b}];

    d64 res = 0;
    int all = a.size() + b.size();
    if (all == 0) return 0.0;
    d64 p = 1.0 / all;

    for (int i = 0; i < a.size(); ++i) {
        std::vector<int> next_a = a;
        next_a[i]--;

        if (next_a[i] == 0) {
            next_a.erase(next_a.begin() + i);
        }
        else {
            std::sort(next_a.begin(), next_a.end());
        }

        res += p * dfs(step + 1, next_a, b);
    }

    for (int i = 0; i < b.size(); ++i) {
        std::vector<int> next_b = b;
        next_b[i]--;

        if (next_b[i] == 0) {
            next_b.erase(next_b.begin() + i);
        }
        else {
            std::sort(next_b.begin(), next_b.end());
        }

        res += p * dfs(step + 1, a, next_b);
    }

    return memory[{step, a, b}] = res;
}

void solve() {
    std::cin >> n >> m >> d;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < m; ++i) std::cin >> b[i];
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    d64 ans = dfs(0, a, b);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(4);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}