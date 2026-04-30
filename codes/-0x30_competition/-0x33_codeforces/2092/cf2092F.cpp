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
    int n;std::cin >> n;
    std::string s;std::cin >> s;s = '&' + s;
    std::vector<int> p;
    for (int i = 2;i <= n;++i)if (s[i] != s[i - 1])p.push_back(i);
    std::vector<int> res(n + 2);
    res[0]++;
    for (int x = 1;x < p.size();++x) {
        int cnt = 1;
        for (int i = x, j = x;i < p.size();i += x, j += x) {
            int y = p[j];
            if (y < n - 1 && s[y] == s[y + 1]) {
                j--;
                cnt++;
            }
            res[y]++;
            if (cnt >= x)break;
            if (i + x < p.size())
                res[p[i + x]]--;
        }
    }
    for (int i = 1;i <= n;++i) {
        res[i] += res[i - 1];
        std::cout << res[i] << ' ';
    }
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