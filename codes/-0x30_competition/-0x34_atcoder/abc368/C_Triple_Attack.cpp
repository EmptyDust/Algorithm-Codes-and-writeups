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
    std::vector<int> h(n);
    for (int& x : h)std::cin >> x;
    int x = 0;i64 sum = 0;
    for (int i = 0;i < n;++i) {
        // std::cout << sum << ' ';
        while (x && h[i] > 0) {
            x = (x + 1) % 3;
            if (x)h[i]--;
            else h[i] -= 3;
            sum++;
        }
        if (h[i] <= 0)continue;
        i64 time = h[i] / 5;
        sum += time * 3;
        h[i] -= time * 5;
        while (h[i] > 0) {
            x = (x + 1) % 3;
            if (x)h[i]--;
            else h[i] -= 3;
            sum++;
        }
    }
    std::cout << sum << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}