#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, k;std::cin >> n >> k;k--;
    std::vector<i64> time(n);
    std::vector<std::vector<pii>> info(n);
    for (int i = 0;i < n;++i) {
        int p;std::cin >> p;
        if (p) {
            int num;std::cin >> num;
            for (int j = 0;j < num;++j) {
                int u, v;std::cin >> u >> v;v--;
                info[i].push_back({ u,v });
            }
        }
        else {
            int t;std::cin >> t;
            time[i] = t;
        }
    }
    if (info[k].empty()) {
        std::cout << time[k];
        return;
    }
    std::function<void(int)> dfs = [&](int x) {
        for (auto [c, type] : info[x]) {
            dfs(type);
            if (time[x] == -1 || time[x] >= 1e9 || time[type] == -1)time[x] = -1;
            else time[x] += c * time[type];
        }
        if (time[x] >= 1e9)time[x] = -1;
        };
    i64 ans = 0, cnt = 0, max = 0;
    for (auto [c, type] : info[k]) {
        dfs(type);
        if (time[type] == -1 || c * time[type] > 1e9)cnt++;
        else {
            ans += c * time[type];
            max = std::max(max, c * time[type]);
        }
    }
    if (cnt >= 2)
        std::cout << "Impossible";
    else if (cnt == 1) {
        if (ans > 1e9) {
            std::cout << "Impossible";
        }
        else std::cout << ans;
    }
    else {
        if (ans - max > 1e9)
            std::cout << "Impossible";
        else
            std::cout << ans - max;
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}