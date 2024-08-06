#include <bits/stdc++.h>

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

bool solve() {
    std::string s;std::cin >> s;
    if (s.length() >= 10) {
        std::map<char, int> mp;
        for (int i = 0;i < 10;++i) {
            mp[s[i]]++;
        }
        if (mp['3'] == 10) {
            return false;
        }
        for (int j = 10;j < s.length();++j) {
            mp[s[j]]++;
            mp[s[j - 10]]--;
            // std::cout << j << ' ' << mp['3'] << '\n';
            if (mp['3'] == 10) {
                return false;
            }
        }
    }
    if (s.length() >= 90) {
        std::map<char, int> mp;
        for (int i = 0;i < 90;++i) {
            mp[s[i]]++;
        }
        if (!mp['5'] && !mp['U']) {
            return false;
        }
        for (int j = 90;j < s.length();++j) {
            mp[s[j]]++;
            mp[s[j - 90]]--;
            if (!mp['5'] && !mp['U']) {
                return false;
            }
        }
    }
    std::string t;
    for (char ch : s)if (ch == '5' || ch == 'U')t += ch;
    for (int i = 0;i < (int)t.length() - 1;++i)if (t[i] == t[i + 1] && t[i] == '5') {
        return false;
    }
    return true;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << (solve() ? "valid" : "invalid");
        std::cout << '\n';
    }
    return 0;
}