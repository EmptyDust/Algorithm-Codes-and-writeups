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
    int n, l, r;std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    l--, r--;
    int len = r - l + 1;
    std::vector<int> p, s;
    for (int i = 0;i <= r;++i)p.push_back(a[i]);
    for (int i = l;i < n;++i)s.push_back(a[i]);
    ranges::sort(p);
    ranges::sort(s);
    i64 sum = 0;
    for (int i = 0;i < len;++i)sum += p[i];
    i64 ans = sum;sum = 0;
    for (int i = 0;i < len;++i)sum += s[i];
    ans = std::min(ans, sum);
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