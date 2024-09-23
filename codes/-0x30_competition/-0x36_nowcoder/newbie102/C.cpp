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
    int n, sum;std::cin >> n >> sum;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    ranges::sort(a);
    int s = std::accumulate(a.begin(), a.end(), 0);
    if (s == sum) {
        std::cout << 0;
    }
    else if (s > sum) {
        int c = s - sum;
        int ans = 0;
        for (int i = n - 1;i >= 0;--i) {
            int t = a[i] - (-1e4);
            c -= t;
            ans++;
            if (c <= 0)break;
        }
        std::cout << ans;
    }
    else {
        int c = sum - s;
        int ans = 0;
        for (int i = 0;i < n;++i) {
            int t = 1e4 - a[i];
            c -= t;
            ans++;
            if (c <= 0)break;
        }
        std::cout << ans;
    }
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