#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string s;std::cin >> s;
    int cnt = 0;
    while (cnt < s.length() && s[cnt] == 'P')cnt++;
    if (cnt == s.length()) {
        std::cout << -1;
        return 0;
    }
    s = s.substr(cnt);
    std::vector<int> vt(1, 1), pos(1, cnt + 1);
    for (int i = 1;i < s.length(); ++i) {
        if (s[i] == s[i - 1])vt.back()++;
        else vt.push_back(1), pos.push_back(i + cnt + 1);
    }
    int maxa = 0, ansi;
    for (int i = 0;i < (int)vt.size() - 1;i += 2) {
        if (std::min(vt[i], vt[i + 1] / 2) > maxa) {
            maxa = std::min(vt[i], vt[i + 1] / 2);
            ansi = pos[i + 1] - maxa;
        }
    }
    if (!maxa) {
        std::cout << -1;
        return 0;
    }
    std::cout << ansi << ' ' << maxa * 3;
    return 0;
}