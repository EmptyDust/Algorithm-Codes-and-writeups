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
    int n, d;std::cin >> n >> d;
    std::vector<int> s(n), p(n);
    for (int& x : s)std::cin >> x;
    for (int& x : p)std::cin >> x;
    std::reverse(p.begin(), p.end());
    int max = s[d - 1] + p.back();
    int cnt = 0;
    for (int i = 0, j = 0;i < d - 1 && j < n - 1;++i) {
        if (s[i] + p[j] > max) {
            cnt++;
        }
        else {
            j++;
        }
    }
    std::cout << cnt + 1 << ' ';
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