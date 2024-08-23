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
    int n, x, k;std::cin >> n >> x >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::priority_queue<int> pq;
    int sum = 0;
    for (int i = 0;i < n;++i) {
        sum += a[i];
        pq.push(a[i]);
        if (sum >= x) {
            if (k) {
                k--;
                // std::cout << pq.top() << ' ';
                sum -= pq.top();
                pq.pop();
            }
            else {
                std::cout << i;
                return;
            }
        }
    }
    std::cout << n;
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