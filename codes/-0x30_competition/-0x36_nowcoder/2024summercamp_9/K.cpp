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
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    int ans = *std::max_element(a.begin(), a.end());
    if (k == 1) {
        std::cout << ans;
        return;
    }
    std::priority_queue<int> pq;
    for (int i = 0;i < n;++i)pq.push(a[i]);
    int cnt = 0;
    while (pq.size()) {
        int x = pq.top();
        pq.pop();
        x /= k;cnt++;
        if (x)pq.push(x);
        if (pq.size()) {
            ans = std::min(ans, cnt + pq.top());
        }
        else ans = std::min(ans, cnt);
    }
    std::cout << ans;
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