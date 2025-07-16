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
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n), rank(n);
    for (auto& x : a)std::cin >> x;
    auto b(a);
    ranges::sort(b);
    int limit = b[k - 1];
    // b.erase(std::unique(b.begin(), b.end()), b.end());
    int cnt = 0;
    for (int i = 0, j = n - 1;i <= j;) {
        // std::cout << cnt << ' ' << i << ' ' << j << '\n';
        if (a[i] < limit || a[j] < limit) {
            while (i <= j && a[i] >= limit) i++;
            while (i <= j && a[j] >= limit) j--;
            if (i <= j && a[i] == a[j]) {
                cnt += i == j ? 1 : 2;
                i++, j--;
            }
            else {
                std::cout << "NO";
                return;
            }
        }
        else if (a[i] == limit && a[j] == limit) {
            cnt += i == j ? 1 : 2;
            i++, j--;
        }
        else if (a[i] == limit) j--;
        else if (a[j] == limit) i++;
        else i++, j--;
    }
    std::cout << (cnt >= k - 1 ? "YES" : "NO");
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