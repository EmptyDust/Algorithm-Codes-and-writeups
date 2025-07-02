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
const int mod = 1e9 + 7;
// const int mod = 998244353;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n), b;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto& x : a)std::cin >> x, pq.push(x);
    int max = ranges::max(a);
    while (k && pq.top() * 2 <= max) {
        pq.push(2 * pq.top());
        pq.pop();
        k--;
    }
    while (pq.size()) {
        b.push_back(pq.top());
        pq.pop();
    }
    i64 res = 0;
    for (int i = 0;i < n;++i) {
        res = (res + b[i] * qpow(2, k / n + (i < k % n)) % mod) % mod;
        // std::cout << res << ' ';
    }
    std::cout << res;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1; //std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}