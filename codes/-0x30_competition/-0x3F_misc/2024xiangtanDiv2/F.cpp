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

int genshin[6] = { 8,1,0,9,7,5 };
i64 k, dp[60][6];

i64 cal(int pos, int cur, bool lim) {
    
}

bool check(i64 x) {
    std::vector<int> num;
    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }
    return cal(num.size(), 0, 1) >= k;
}

void solve() {
    std::cin >> k;
    i64 l = 0, r = 1e18 + 1;
    auto check = [&](auto x)->bool {

        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    std::cout << l;
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