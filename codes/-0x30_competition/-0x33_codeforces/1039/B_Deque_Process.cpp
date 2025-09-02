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
    int n;std::cin >> n;
    std::vector<int> a(n), b;
    std::string ans;
    for (auto& x : a)std::cin >> x;
    for (int i = 0, j = n - 1;i <= j;++i, --j) {
        if (i == j) b.push_back(a[i]), ans += 'L';
        else {
            int min = std::min(a[i], a[j]);char minc = min == a[i] ? 'L' : 'R';
            int max = std::max(a[i], a[j]);char maxc = max == a[i] ? 'L' : 'R';
            if (b.empty()) {
                b.push_back(a[i]), b.push_back(a[j]);
                ans += 'L', ans += 'R';
            }
            else if (b.back() <= min) {
                b.push_back(max), b.push_back(min);
                ans += maxc; ans += minc;
            }
            else if (b.back() >= max) {
                b.push_back(min), b.push_back(max);
                ans += minc; ans += maxc;
            }
            else {
                b.push_back(min), b.push_back(max);
                ans += minc; ans += maxc;
            }
        }
    }
    // for (auto x : b)std::cout << x << " ";std::cout << '\n';
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