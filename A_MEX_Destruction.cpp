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
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    if (std::count(a.begin(), a.end(), 0) == n) {
        std::cout << 0;
        return;
    }
    while (a.size() && a.back() == 0) a.pop_back();
    int s = 0;
    while (a.size() && a[s] == 0) s++;
    if (std::count(a.begin() + s, a.end(), 0) == 0) {
        std::cout << 1;
        return;
    }
    std::cout << 2;
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