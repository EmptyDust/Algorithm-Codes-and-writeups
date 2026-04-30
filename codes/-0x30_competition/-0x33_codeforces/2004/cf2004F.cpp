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
    std::vector<int> a(n), p(n + 1);
    for (int& x : a)std::cin >> x;
    for (int i = 1;i <= n;++i)p[i] = p[i - 1] + a[i - 1];
    std::map<int, int> cnt;
    int ans = 0;
    for (int len = 0;len <= n;++len) {
        for (int i = 0;i <= n - len;++i) {
            int s = p[i + len] + p[i];
            ans += len;
            ans -= 2 * cnt[s];
            ans -= (s % 2 || !std::binary_search(p.begin(), p.end(), s / 2));
            cnt[s]++;
        }
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