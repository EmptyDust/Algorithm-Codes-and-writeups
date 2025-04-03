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

char yuan[5] = { 'A','E','I','O','U' };

void solve() {
    std::string s;std::cin >> s;
    int n = s.length();
    std::map<char, int> mp;
    for (char ch : s)mp[ch]++;
    int ng = std::min(mp['N'], mp['G']);
    int y = 0, f = 0, yc = mp['Y'];
    for (auto [ch, cnt] : mp) {
        bool ok = true;
        for (int i = 0;i < 5;++i)if (yuan[i] == ch) {
            ok = false;
            y += cnt;
            break;
        }
        if (ok && ch != 'Y')f += cnt;
    }
    bool tag = false;
    while (yc && y * 2 < f)y++, yc--, tag = true;
    while (yc && y * 2 > f)f++, yc--;
    if (tag && y * 2 > f)y--, f++;
    // std::cout << y << ' ' << f << '\n';
    if (yc) {
        int cnt = std::min(y, f / 2) + yc / 3;
        std::cout << cnt * 3;
    }
    else if (y * 2 <= f) {
        int cnt = y;
        int ans = cnt * 3 + std::min({ cnt * 2, ng, f - 2 * y });
        std::cout << ans;
    }
    else {
        int cnt = f / 2;
        std::cout << cnt * 3;
    }
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