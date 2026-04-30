#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    for (int i = n;i;--i) {
        std::priority_queue<int, std::vector<int>, std::greater<int>>pq;
        for (int j = 0;j < n;++j) {
            bool fi = (s[j] == '1');
            while (pq.size() && pq.top() <= j)pq.pop();
            bool f = pq.size() % 2;
            if (f == fi) {
                pq.push(i + j);
            }
        }
        while (pq.size() && pq.top() <= n)pq.pop();
        if (pq.empty()) {
            std::cout << i;
            return;
        }
    }
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