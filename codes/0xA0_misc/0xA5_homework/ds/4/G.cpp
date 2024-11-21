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
    int m;std::cin >> m;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0;i < m;++i) {
        int op;std::cin >> op;
        if (op) {
            int x;std::cin >> x;
            pq.push(x);
        }
        else {
            if (pq.size()) {
                std::cout << pq.top() << '\n';
                pq.pop();
            }
            else std::cout << -1 << '\n';
        }
    }
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