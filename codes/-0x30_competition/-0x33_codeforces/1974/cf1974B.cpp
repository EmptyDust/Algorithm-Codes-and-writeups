#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    std::string s;std::cin >> s;
    std::vector<bool> st(26, false);
    std::string t;
    for (char ch : s)if (!st[ch - 'a']) {
        st[ch - 'a'] = 1;
        t += ch;
    }
    std::sort(t.begin(), t.end());
    std::map<char, char> mp;
    for (int l = 0, r = t.length() - 1;l <= r;) {
        mp[t[l]] = t[r];
        mp[t[r]] = t[l];
        l++, r--;
    }
    for (char& ch : s)ch = mp[ch];
    std::cout << s;
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