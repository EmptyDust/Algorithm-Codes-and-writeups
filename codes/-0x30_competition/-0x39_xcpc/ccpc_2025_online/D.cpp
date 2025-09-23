#include<bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;
using u32 = unsigned;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

#define int long long

const int mod = 1e9 + 7;
const int inf = 1e9;

std::vector<int> kmp(std::string& s, std::string& t) {
    int n = s.length(), m = t.length();
    std::vector<int> ans, next(m + 1, -1);
    for (int i = 0, j = -1;i < m;) {
        if (j == -1 || t[i] == t[j]) {
            ++i, ++j;
            next[i] = j;
        }
        else j = next[j];
    }
    // for (auto x : next)std::cout << x << " ";std::cout << '\n';
    for (int i = 0, j = 0;i < n;) {
        if (j == -1 || s[i] == t[j]) {
            ++i, ++j;
            // std::cout << j << ' ';
            if (j == m) {
                ans.push_back(i - m);
                j = next[j];
            }
        }
        else j = next[j];
    }
    return ans;
}

void solve() {
    std::string s, t;std::cin >> s >> t;
    std::vector pos(100, std::vector<int>());
    std::vector<int> len(100);
    std::string tmp;int cnt = 0;
    for (auto ch : s) {
        if (ch == '*') {
            if (!tmp.empty()) {
                pos[cnt] = kmp(t, tmp);
                len[cnt] = tmp.length();
                if (pos[cnt].empty()) {
                    std::cout << 0;
                    return;
                }
                cnt++;
                tmp = "";
            }
        }
        else tmp += ch;
    }
    if (!tmp.empty()) {
        pos[cnt] = kmp(t, tmp);
        len[cnt] = tmp.length();
        cnt++;
    }
    int n = t.length();
    if (cnt == 0) {
        std::cout << 1ll * n * (n + 1) / 2;
        return;
    }
    if (s.front() != '*' && s.back() != '*' && cnt == 1) {
        std::cout << pos[0].size();
        return;
    }
    std::vector<int> dp(n);
    auto work = [&](std::vector<int>& next, int length) {
        auto ndp = std::vector<int>(n, -1);
        for (int i = 0;i < n;++i) if (dp[i] != -1) {
            auto it = std::lower_bound(next.begin(), next.end(), dp[i]);
            if (it == next.end()) ndp[i] = -1;
            else ndp[i] = (*it) + length;
        }
        dp = ndp;
        };
    if (s[0] != '*') {
        dp.assign(n, -1);
        for (auto x : pos[0]) {
            dp[x] = x + len[0];
        }
        for (int i = 1;i < cnt;++i) {
            work(pos[i], len[i]);
        }
    }
    else {
        for (int i = 0;i < n;++i) dp[i] = i;
        // for (auto x : dp)std::cout << x << " ";std::cout << "\n";
        for (int i = 0;i < cnt;++i) {
            work(pos[i], len[i]);
        }
        // for (auto x : dp)std::cout << x << " ";std::cout << "\n";
    }
    if (s.back() != '*') {
        i64 ans = 0;
        auto& last = pos[cnt - 1];
        int lastlen = len[cnt - 1];
        for (int i = 0;i < n;++i) if (dp[i] != -1) {
            int res = last.size() - (std::lower_bound(last.begin(), last.end(), dp[i] - lastlen) - last.begin());
            ans += res;
        }
        std::cout << ans;
    }
    else {
        i64 ans = 0;
        for (int i = 0;i < n;++i) if (dp[i] != -1) {
            ans += n - dp[i] + 1;
            // std::cout << n - dp[i] << ' ';
        }
        std::cout << ans;
    }
}

signed main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}