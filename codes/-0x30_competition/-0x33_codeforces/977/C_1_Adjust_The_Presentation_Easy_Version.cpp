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
    int n, m, q;std::cin >> n >> m >> q;
    std::vector<int> a(n), b(m), t, s;
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    std::vector<int> pos(n + 1);
    for (int i = 0;i < n;++i) {
        if (!pos[a[i]]) {
            t.push_back(a[i]);
            pos[a[i]] = t.size();
        }
    }
    std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> info(n + 1);
    for (int i = 0;i < m;++i) {
        info[b[i]].push(i);
    }
    int cnt = 0;
    auto insert = [&](int x, int p) {
        
        };
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