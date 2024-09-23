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

bool check(std::string& a, std::string& c) {
    std::vector<int> m(26), n(26);
    for (char ch : a)m[ch - 'a']++;
    for (char ch : c)n[ch - 'a']++;
    for (int i = 0;i < 26;++i) {
        if (n[i] && !m[i])return false;
    }
    return true;
}

void solve() {
    int b, d;std::cin >> b >> d;
    std::string a, c;std::cin >> a >> c;
    if (!check(a, c)) {
        std::cout << 0;
        return;
    }
    int n = a.length(), m = c.length();
    std::vector<std::vector<i64>> nxt(30, std::vector<i64>(n));
    for (int i = 0;i < n;++i) {
        int now = i;
        for (int j = 0;j < m;++j) {
            while (a[now % n] != c[j]) {
                now++;
            }
            now++;
        }
        nxt[0][i] = now;
    }
    for (int s = 1;s < 30;++s) {
        for (int i = 0;i < n;++i) {
            nxt[s][i] = nxt[s - 1][i] + nxt[s - 1][nxt[s - 1][i] % n] - nxt[s - 1][i] % n;
        }
    }
    i64 cur = 0, ans = 0;
    for (int s = 29;s >= 0;--s) {
        if (cur + nxt[s][cur % n] - cur % n <= 1ll * n * b) {
            cur += nxt[s][cur % n] - cur % n;
            ans |= 1 << s;
        }
    }
    std::cout << ans / d;
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