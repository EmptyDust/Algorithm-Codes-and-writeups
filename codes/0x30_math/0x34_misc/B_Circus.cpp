#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::string s, t;std::cin >> s >> t;
    int x1, y1, x2, y2;
    //x1 = y2 ==> x1 + x2 = y2 + x2
    int l = std::count(s.begin(), s.end(), '1');
    std::vector<int> ans;
    std::vector<std::vector<int>> cnt(3);
    for (int i = 0;i < n;++i) {
        cnt[s[i] + t[i] - 2 * '0'].push_back(i + 1);
    }
    for (int b = 0;b <= cnt[2].size();++b) {
        int d = l - b * 2;
        if (0 <= d && d <= cnt[1].size() && 0 <= n / 2 - b - d && n / 2 - b - d <= cnt[0].size()) {
            std::vector<int> ans;
            for (int i = b;i < cnt[2].size();++i)ans.push_back(cnt[2][i]);
            for (int i = d;i < cnt[1].size();++i)ans.push_back(cnt[1][i]);
            for (int i = 0;ans.size() < n / 2;++i)ans.push_back(cnt[0][i]);
            for (int x : ans)std::cout << x << ' ';
            return 0;
        }
    }
    std::cout << -1;
    return 0;
}