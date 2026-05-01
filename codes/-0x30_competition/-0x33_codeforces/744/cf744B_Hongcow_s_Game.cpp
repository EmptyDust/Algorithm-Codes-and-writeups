#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<int> min(n + 1, inf);
    std::vector<std::vector<int>> p(10, std::vector<int>(n + 1));
    auto query = [&](std::vector<int>& q, int i, bool f) {
        if (q.size()) {
            std::cout << q.size() << '\n';
            for (int x : q)std::cout << x << " ";
            std::cout << std::endl;
            for (int j = 1;j <= n;++j) {
                int x;std::cin >> x;
                if (p[i][j] != f) {
                    min[j] = std::min(min[j], x);
                }
            }
            q.clear();
        }
        };
    for (int i = 0;i < 10;++i) {
        for (int j = 1;j <= n;++j) {
            p[i][j] = j >> i & 1;
        }
        std::vector<int> q;
        for (int j = 1;j <= n;++j) {
            if (p[i][j]) {
                q.push_back(j);
            }
        }
        query(q, i, 1);
        for (int j = 1;j <= n;++j) {
            if (!p[i][j]) {
                q.push_back(j);
            }
        }
        query(q, i, 0);
    }
    std::cout << -1 << std::endl;
    for (int i = 1;i <= n;++i)std::cout << min[i] << ' ';
    std::cout << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}