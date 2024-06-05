#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<std::vector<int>> map1(n, std::vector<int>(m)), map2(map1);
    std::vector<std::vector<int>> _map1(m, std::vector<int>(n)), _map2(_map1);
    for (auto& vt : map1)for (auto& num : vt)std::cin >> num;
    for (auto& vt : map2)for (auto& num : vt)std::cin >> num;
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        _map1[j][i] = map1[i][j];
        _map2[j][i] = map2[i][j];
    }

    std::sort(map1.begin(), map1.end(), [&](auto& a, auto& b) {
        return *std::min_element(a.begin(), a.end()) < *std::min_element(b.begin(), b.end());
        });
    std::sort(map2.begin(), map2.end(), [&](auto& a, auto& b) {
        return *std::min_element(a.begin(), a.end()) < *std::min_element(b.begin(), b.end());
        });
    auto cmp = [&](std::vector<int> a, std::vector<int> b)->bool {
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        return a == b;
        };
    for (int i = 0;i < n;++i) {
        if (!cmp(map1[i], map2[i])) {
            std::cout << "NO";
            return;
        }
    }

    std::sort(_map1.begin(), _map1.end(), [&](auto& a, auto& b) {
        return *std::min_element(a.begin(), a.end()) < *std::min_element(b.begin(), b.end());
        });
    std::sort(_map2.begin(), _map2.end(), [&](auto& a, auto& b) {
        return *std::min_element(a.begin(), a.end()) < *std::min_element(b.begin(), b.end());
        });
    for (int i = 0;i < m;++i) {
        if (!cmp(_map1[i], _map2[i])) {
            std::cout << "NO";
            return;
        }
    }

    std::cout << "YES";
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