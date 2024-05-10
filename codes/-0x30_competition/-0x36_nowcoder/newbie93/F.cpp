#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    std::string str;std::cin >> str;
    int n = str.length();
    for (int len = 1;len <= n;++len) if (n % len == 0) {
        std::string ans;
        int p = 0;
        for (int s = 0;s < len;++s) {
            std::map<char, int> mp;
            int max = 0;
            char maxc;
            for (int t = s;t < n;t += len) {
                mp[str[t]]++;
                if (mp[str[t]] > max) {
                    max = mp[str[t]];
                    maxc = str[t];
                }
            }
            p += max;
            ans += maxc;
        }
        if (p >= (n + 1) / 2) {
            int time = p - (n + 1) / 2;
            for (int s = 0;s < len;++s) {
                std::map<char, int> mp;
                for (int t = s;t < n;t += len)
                    mp[str[t]]++;
                char change = '*';int cost = 0;
                for (auto ch = ans[s] - 1;ch >= 'a';--ch)if (mp[ans[s]] - mp[ch] <= time) {
                    change = ch;
                    cost = mp[ans[s]] - mp[ch];
                }
                if (change != '*') {
                    time -= cost;
                    ans[s] = change;
                }
            }
            std::cout << ans;
            return;
        }
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