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
    int n, k;std::cin >> n >> k;
    std::string s;std::cin >> s;std::reverse(s.begin(), s.end());
    std::vector<std::string> a(n);
    for (int i = 0;i < n;++i)std::cin >> a[i], std::reverse(a[i].begin(), a[i].end());
    std::vector<int> cnt(k), target(k);
    for (int i = 0;i < k;++i)target[i] = s[i] == '1';
    for (int i = 0;i < n;++i)for (int j = 0;j < k;++j) {
        cnt[j] += a[i][j] == '1';
    }
    std::vector memo(k, std::vector<bool>(n));
    std::string res = "";
    std::function<bool(int, int)> dfs = [&](int p, int now) {
        if (p == k) {
            return now == 0;
        }
        if (memo[p][now])return false;
        memo[p][now] = true;
        for (int i = 0;i < 2;++i) {
            int tmp = now;
            if (i)tmp += n - cnt[p];
            else tmp += cnt[p];
            if (tmp % 2 == target[p] && dfs(p + 1, tmp / 2)) {
                res += char(i + '0');
                return true;
            }
        }
        return false;
        };
    dfs(0, 0);
    if (res.size())
        std::cout << res;
    else std::cout << -1;
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