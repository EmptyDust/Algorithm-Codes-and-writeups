#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 4e6;
const int MAXN = 4e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x, x += 2e6;
    std::vector<int> mp(MAXN), add(MAXN), max(MAXN);
    for (int& x : a)
        mp[x]++;
    int ans = 0;
    if (k == 0){
        for (auto& cnt : mp){
            ans = std::max(ans, cnt);
        }
        std::cout << ans;
        return;
    }
    for (int& x : a){
        add[x] = std::max(0, add[x] - 1);
        max[x] = std::max(max[x], add[x]);
        add[x + k]++;
        max[x + k] = std::max(max[x + k], add[x + k]);
    }
    for (int i = 0;i < MAXN;++i){
        ans = std::max(ans, mp[i] + max[i]);
    }
    std::cout << ans;
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