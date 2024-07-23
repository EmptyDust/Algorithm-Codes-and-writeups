#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::ranges::sort(a);
    std::map<int, int> mp;
    for (int x : a)mp[x]++;
    std::vector<int> ps;
    for (auto [x, cnt] : mp)ps.push_back(cnt);
    std::reverse(ps.begin(), ps.end());
    for (int i = 0;i < ps.size();++i) {
        if (ps[i] % 2 == 1) {
            std::cout << "YES";
            return;
        }
    }
    std::cout << "NO";
    return;
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