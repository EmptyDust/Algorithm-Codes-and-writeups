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
    std::vector<int> a(n), ans(n);
    for (auto& x : a)std::cin >> x;
    bool ok = false;
    int hi = n, lo = 1, cur = 1;
    while (!ok) {
        ok = true;
        auto it = std::find(a.begin(), a.end(), cur + 1);
        if (it == a.end())it = std::find(a.begin(), a.end(), -1);
        auto p = it - a.begin();
        for (int i = 0;i <= p;++i) {
            if (a[i] == cur) {
                if (cur % 2) {
                    ans[i] = hi--;
                }
                else ans[i] = lo++;
                ok = false;
            }
        }
        for (int i = n - 1;i > p;--i) {
            if (a[i] == cur) {
                if (cur % 2) {
                    ans[i] = hi--;
                }
                else ans[i] = lo++;
                ok = false;
            }
        }
        cur++;
    }
    for (int i = 0;i < n;++i)if (a[i] == -1)ans[i] = lo;
    for (auto& x : ans)std::cout << x << " ";
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