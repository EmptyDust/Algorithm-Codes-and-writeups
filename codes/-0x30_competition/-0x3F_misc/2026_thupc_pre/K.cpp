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
    i64 n, m, L, a, b;std::cin >> n >> m >> L >> a >> b;
    std::map<i64, int> sta;
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        sta[x] |= 1;
    }
    for (int i = 0;i < m;++i) {
        int x;std::cin >> x;
        sta[x] |= 2;
    }
    std::deque<a2> ra, rb;
    ra.push_back({ 0, 1 });
    rb.push_back({ 0, 1 });
    for (auto [x, s] : sta) if (x != 0) {
        if (s >> 0 & 1) {
            
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