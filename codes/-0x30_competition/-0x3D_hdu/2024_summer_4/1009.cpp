#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

int days[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

void solve() {
    int n, m;std::cin >> n >> m;
    std::string s;std::cin >> s;
    std::string t;
    std::vector<int> mp;
    for (int i = 0;i < m;++i) {
        if ('a' <= s[i] && s[i] <= 'z') {
            t.push_back(s[i]);
            mp.push_back(i);
        }
    }
    // std::cout << t << '\n';
    std::vector next(m + 1, std::vector<int>(26));
    for (char ch = 'a';ch <= 'z';++ch) {
        int cur = -1;
        for (int i = m;i >= 0;--i) {//1-indexed
            // if (ch == 'c' && i == 2)std::cout << cur << ' ';
            next[i][ch - 'a'] = cur;//i位置后的第一个ch的位置为cur
            if (i && s[i - 1] == ch) cur = i;
        }
    }
    //l a l a i l l
    //3 3 6 6 6 7 -1
    std::vector<int> pos(n);
    for (int i = 0;i < n;++i) {
        std::string name;std::cin >> name;
        int cur = 0;
        for (char ch : name) {
            cur = next[cur][ch - 'a'];
            if (cur == -1) {
                break;
            }
        }
        pos[i] = cur - 1;
    }
    // for (int i = 0;i < n;++i)std::cout << pos[i] << ' ';
    std::vector<int> res(m + 1);
    int N = 1232;
    std::vector<bool> dp(N);
    std::vector<bool> dp2(N);
    std::vector<bool> dp3(N);
    std::vector<bool> dp4(N);// abcd

    for (int i = m - 1;i >= 0;--i) {
        if (!('0' <= s[i] && s[i] <= '9')) {
            res[i] = res[i + 1];
            continue;
        }
        int ch = s[i] - '0';
        if (ch < 2) {
            int a = ch * 1000;
            for (int b = 0;b < 10 && a + b * 100 < N;++b) {
                for (int cd = 1;cd <= days[ch * 10 + b];++cd) {
                    int bcd = b * 100 + cd;
                    // std::cout << a + bcd << '\n';
                    dp[a + bcd] = dp[a + bcd] | dp2[bcd];
                }
            }
        }
        {
            int b = ch * 100;
            for (int cd = 1;cd <= 31;++cd) {
                dp2[b + cd] = dp2[b + cd] | dp3[cd];
            }
        }
        {
            int c = ch * 10;
            for (int d = 0;d < 10;++d) {
                dp3[c + d] = dp3[c + d] | dp4[d];
            }
        }
        {
            int d = ch;
            dp4[d] = 1;
        }
        for (int ab = 1;ab <= 12;++ab)for (int cd = 1;cd <= days[ab];++cd) {
            if (dp[ab * 100 + cd])res[i]++;
        }
    }
    // for (int i = 0;i < m;++i)std::cout << res[i] << ' ';

    i64 ans = 0;
    // std::cout << cnt2[14][2] << '\n';
    for (int x : pos)if (x >= 0) {
        // std::cout << x << ' ';
        ans += res[x];
    }
    std::cout << ans;
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