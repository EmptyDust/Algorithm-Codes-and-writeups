#include <bits/stdc++.h>

using i64 = long long;

auto add(std::string s, std::string t) {
    std::reverse(s.begin(), s.end());
    std::reverse(t.begin(), t.end());
    while (s.size() < t.size())s.push_back('0');
    while (s.size() > t.size())t.push_back('0');
    s.push_back('0');
    t.push_back('0');
    bool j = false;
    std::string ret;
    for (int i = 0;i < s.length();++i) {
        int res = (s[i] == '1') + (t[i] == '1') + j;
        if (res % 2)ret.push_back('1');
        else ret.push_back('0');
        if (res / 2)j = 1;
        else j = 0;
    }
    while (ret.size() > 1 && ret.back() == '0')ret.pop_back();
    std::reverse(ret.begin(), ret.end());
    return ret;
}

void solve() {
    std::string s;std::cin >> s;
    //16 + 4 + 1
    auto res = add(s, s + "00");
    res = add(res, s + "0000");
    std::cout << res;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}