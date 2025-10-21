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
    for (auto& [x, y] : info)std::cin >> x >> y;
    if (n == 1) {
        if (info[0] == a2{ 2, 2 }) {
            std::cout << "NO\n";
        }
        else {
            std::cout << "YES\n";
            std::cout << 1 << " " << 1 << '\n';
        }
        return;
    }
    for (int i = 2;i <= 2 * n;i += 2) {
        bool f = false;
        for (auto [j, _] : info) {
            if (j == i) {
                f = true;
                break;
            }
        }
        if (!f) {
            // std::cout << i << '\n';
            std::cout << "YES\n";
            for (int j = 1;j <= n;++j) {
                std::cout << i / 2 << ' ' << j << '\n';
            }
            return;
        }
    }
    int y1, y2;
    for (auto [x, y] : info) {
        if (x == 2) {
            y1 = y;
            break;
        }
    }
    for (auto [x, y] : info) {
        if (x == 4) {
            y2 = y;
            break;
        }
    }
    std::vector<a2> ans;
    if (y1 <= n) {
        for (int j = n;j >= n / 2 && j * 2 != y1;--j) {
            ans.push_back({ 1, j });
        }
    }
    else {
        for (int j = 1;j <= (n + 1) / 2 && j * 2 != y1;++j) {
            ans.push_back({ 1, j });
        }
    }
    if (y2 <= n) {
        for (int j = n;j >= n / 2 && j * 2 != y2;--j) {
            ans.push_back({ 2, j });
        }
    }
    else {
        for (int j = 1;j <= (n + 1) / 2 && j * 2 != y2;++j) {
            ans.push_back({ 2, j });
        }
    }
    assert(ans.size() >= n);
    ans.resize(n);
    std::cout << "YES\n";
    for (auto [x, y] : ans) {
        std::cout << x << ' ' << y << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}