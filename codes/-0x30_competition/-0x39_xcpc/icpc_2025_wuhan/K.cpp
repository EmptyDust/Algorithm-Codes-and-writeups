#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<a2> info(n);
    std::vector target(n, std::vector(2, a2()));
    for (auto& [a, b] : info)std::cin >> a;
    for (auto& [a, b] : info)std::cin >> b;
    std::vector<a2> ans;
    auto swap = [&](int x, int y) {
        auto [a1, b1] = target[x][0];
        target[a1][b1] = { y, 1 };
        auto [a2, b2] = target[y][1];
        target[a2][b2] = { x, 0 };
        std::swap(info[x][0], info[y][1]);
        std::swap(target[x][0], target[y][1]);
        ans.push_back({ x + 1, y + 1 });
        };
    i64 cost = 0;
    std::vector pre(n + 1, a2{ -1, -1 });
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < 2;++j) {
            auto& [a, b] = pre[info[i][j]];
            if (a != -1) {
                cost += i - a;
                // std::cout << i << ' ' << j << ' ' << i - a << '\n';
                target[a][b] = { i, j };
                target[i][j] = { a, b };
                a = -1, b = -1;
            }
            else a = i, b = j;
        }
    }
    for (int i = 1;i <= n;++i) if (pre[i][0] != -1) {
        std::cout << -1 << '\n';
        return;
    }
    for (int i = 0;i < n;++i) if (info[i][0] != info[i][1]) {
        std::vector<a2> stack;
        stack.push_back({ i, 0 });
        while (stack.size()) {
            auto [x, y] = stack.back();
            auto [a, b] = target[x][y];
            auto [c, d] = target[a][!b];
            if (c <= x) {
                if (y != 0) swap(x, x);
                if (b != 0) swap(a, a);
                swap(x, a);
                stack.pop_back();
            }
            else if (c < a) {
                if (d != 0) swap(c, c);
                if (b != 1) swap(a, a);
                swap(c, a);
            }
            else {
                stack.push_back({ a, !b });
            }
        }
    }
    std::cout << cost / 2 << ' ' << ans.size() << '\n';
    for (auto [x, y] : ans)std::cout << x << ' ' << y << "\n";
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