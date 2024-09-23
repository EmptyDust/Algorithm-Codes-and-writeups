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
    int n, m, q;std::cin >> n >> m >> q;
    std::vector<int> a(m), b(q);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    ranges::sort(a);
    std::vector<int> ans;
    auto cal = [&](int x) {
        return x / 2;
        };
    for (int x : b) {
        auto it = std::upper_bound(a.begin(), a.end(), x);
        if (it == a.begin()) {
            ans.push_back((*a.begin()) - 1);
        }
        else if (it == a.end()) {
            ans.push_back(n - (*--it));
        }
        else {
            int c = ((*it) - (*--it)) / 2;
            ans.push_back(c);
        }
    }
    for (int x : ans)std::cout << x << " ";
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