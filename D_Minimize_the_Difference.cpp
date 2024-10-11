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
    int n;std::cin >> n;
    std::vector<i64> a(n);
    for (i64& x : a)std::cin >> x;
    std::deque<pii> dq;
    std::reverse(a.begin(), a.end());
    for (i64 x : a) {
        i64 len = 1;
        while (dq.size() && x / len >= dq.back().first) {
            x += dq.back().first * dq.back().second;
            len += dq.back().second;
            dq.pop_back();
        }
        i64 y = x % len;
        if (y)dq.push_back({ x / len + 1, y });
        dq.push_back({ x / len,len - y });
        // std::cout << dq.back().first << ' ' << dq.back().second << '\n';
    }
    std::cout << dq.front().first - dq.back().first;
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