#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

int dp[16][65536], n;

int cal(std::string& s) {
    int x = 0;
    for (char ch : s)x = x * 2 + (ch == 'B');
    return x;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    memset(dp, -1, sizeof dp);
    std::cin >> n;
    std::string s, t;std::cin >> s >> t;
    s += "  ";
    t += "  ";
    std::queue<std::pair<int, std::pair<std::string, int>>> q;
    q.push({ 0, {s,n} });
    while (q.size()) {
        auto [cnt, p] = q.front();
        auto [s, t] = p;
        q.pop();
        int x = cal(s);
        if (dp[t][x] != -1)continue;;
        dp[t][x] = cnt;
        for (int i = 0;i < t - 1;++i) {
            std::string tmp = s;
            std::swap(tmp[i], tmp[t]);
            std::swap(tmp[i + 1], tmp[t + 1]);
            q.push({ cnt + 1 ,{tmp,i} });
        }
        for (int i = t + 2;i < s.length() - 1;++i) {
            std::string tmp = s;
            std::swap(tmp[i], tmp[t]);
            std::swap(tmp[i + 1], tmp[t + 1]);
            q.push({ cnt + 1 ,{tmp,i} });
        }
    }
    std::cout << dp[n][cal(t)];
    return 0;
}