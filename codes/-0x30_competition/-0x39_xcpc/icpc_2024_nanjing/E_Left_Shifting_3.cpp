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
    int n, k; std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    s += s.substr(0, std::min(6, k));
    int sz = s.length();
    std::vector<int> a(sz);
    int ans = 0;
    for (int i = 0;i < sz - 6;++i){
        if (s.substr(i, 7) == "nanjing"){
            ans++;
        }
    }
    std::cout << ans << '\n';

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
    return 0;
}