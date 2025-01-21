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

i64 muldule(i64 a, i64 b) {
    return (a % b + b) % b;
}

void solve() {
    i64 n, k;std::cin >> n >> k;k *= 2;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::string ans;
    i64 cur = (muldule(a[0], k) <= muldule(a[1], k)) ? 1 : -1;
    for (int i = 1;i < n;++i) {
        ans += (cur + ((muldule(a[i], k) <= muldule(a[0], k)) ? 1 : -1) == 0) ? '0' : '1';
        if (i < n)cur += (muldule(a[i], k) <= muldule(a[i + 1], k)) ? 1 : -1;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}