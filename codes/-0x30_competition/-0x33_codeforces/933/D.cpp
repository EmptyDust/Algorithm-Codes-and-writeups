#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, m, x;std::cin >> n >> m >> x;x--;
    std::set<int> p;
    p.insert(x);
    while (m--) {
        std::set<int> tmp;
        int len;char dir;
        std::cin >> len >> dir;
        int sz = p.size();
        for (int num : p) {
            if (dir != '1') tmp.insert((num + len) % n);
            if (dir != '0') tmp.insert((num - len % n + n) % n);
        }
        p = tmp;
    }
    std::cout << p.size() << '\n';
    for (int num : p)std::cout << num + 1 << ' ';
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