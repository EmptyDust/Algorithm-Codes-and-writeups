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
    std::vector<int> a(n), b(n);
    for (int& x : a)std::cin >> x, b[x]++;
    if (!b[0]) {
        std::cout << 0;
        return;
    }
    b[0]--;
    i64 ans = 0;
    int mex = 1;
    for (int i = 1;i < n;++i) {
        if (b[i]) {
            b[i]--;
            ans += mex;
            mex++;
        }
        else {
            break;
        }
    }
    ans += std::accumulate(b.begin(), b.end(), 0ll) * mex + b[0];
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