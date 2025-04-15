#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    std::vector<i64> num(1, 1);
    for (i64 a = 1;a <= 1e18;a = a * 4 + 1) {
        num.push_back(a * 4 + 1);
    }
    int n = num.size();
    i64 L, R, k; std::cin >> L >> R >> k; L--;

    if (k > 120) {
        std::cout << 0;
        return;
    }

    std::vector<int> l;
    for (int i = n - 1;i >= 0;--i) {
        l.push_back(L / num[i]);
        L %= num[i];
    }

    std::vector<int> r;
    for (int i = n - 1;i >= 0;--i) {
        r.push_back(R / num[i]);
        R %= num[i];
    }

    std::vector dp(32, std::vector<a2>(120, { -1,-1 }));
    auto dfs = [&](this auto&& self, std::vector<int>& num, int pos, int sum, bool is_up, bool has_4)->i64 {
        if (pos == num.size() && sum == k)return 1;
        if (sum > k || pos >= num.size())return 0;
        if (!is_up && ~dp[pos][sum][has_4])return dp[pos][sum][has_4];
        int up = has_4 ? 0 : (is_up ? num[pos] : 4);
        i64 res = 0;
        for (int x = 0;x <= up;++x) {
            res += self(num, pos + 1, sum + x, is_up && x == up, has_4 | x == 4);
        }
        if (!is_up)dp[pos][sum][has_4] = res;
        return res;
        };
    std::cout << dfs(r, 0, 0, 1, 0) - dfs(l, 0, 0, 1, 0);
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