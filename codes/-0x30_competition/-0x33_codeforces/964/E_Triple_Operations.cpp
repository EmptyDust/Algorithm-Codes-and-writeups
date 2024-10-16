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

std::vector<int> a;

void solve() {
    int l, r;std::cin >> l >> r;
    int _l = l;
    int cnt = 0;
    while (_l) {
        _l /= 3;
        cnt++;
    }
    l++;
    i64 ans = cnt * 2;
    for (int i = 0;i < a.size();++i) {
        if (r < a[i]) {
            int len = r - l + 1;//[l,r]
            ans += len * i;
            break;
        }
        if (a[i] > l) {
            int len = a[i] - l;//[l , x)
            ans += len * i;
            l = a[i];
        }
        // std::cout << ans << ' ';
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    a.push_back(1);
    while (a.back() <= 2e5)a.push_back(a.back() * 3);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}