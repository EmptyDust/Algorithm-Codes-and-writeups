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
    i64 n, l, r;std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    ranges::sort(a);
    std::vector<int> L, R, M;
    for (auto x : a) {
        if (x < l) L.push_back(x);
        else if (x > r) R.push_back(x);
        else M.push_back(x);
    }
    for (int i = 0, j = M.size() - 1;i <= j;) {
        if (L.size() <= R.size()) {
            L.push_back(M[i]); ++i;
        }
        else {
            R.push_back(M[j]); --j;
        }
    }
    // for (auto x : L)std::cout << x << " ";std::cout << '\n';
    // for (auto x : R)std::cout << x << " ";std::cout << '\n';
    int k = std::min(L.size(), R.size());
    i64 ans = 0;
    for (int i = 0;i < k;++i) {
        ans += R[i] - L[i];
    }
    for (int i = k;i < L.size();++i) {
        ans += std::max(0ll, l - L[i]);
    }
    for (int i = k;i < R.size();++i) {
        ans += std::max(0ll, R[i] - r);
    }
    std::cout << ans;
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