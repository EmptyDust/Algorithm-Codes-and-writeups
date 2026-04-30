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
    std::vector<int> a(n), vis(n, 1);
    for (int& x : a)std::cin >> x;
    std::stack<int> p;
    int min = inf;
    for (int i = 0;i < n;++i) {
        while (p.size() && a[p.top()] > a[i]) {
            min = std::min(min, a[p.top()] + 1);
            p.pop();
        }
        p.push(i);
    }
    while (p.size()) {
        if (a[p.top()] <= min)
            vis[p.top()] = 0;
        p.pop();
    }
    for (int i = 0;i < n;++i)a[i] += vis[i];
    ranges::sort(a);
    for (int x : a)std::cout << x << ' ';
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