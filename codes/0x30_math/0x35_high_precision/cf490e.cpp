#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::vector<std::string> strings(n), ans(n);
    for (auto& str : strings)std::cin >> str;
    {
        auto& str = strings[0];
        auto& res = ans[0] = str;
        int sz = str.length();
        for (int i = sz - 1;i >= 0;--i)
            if (strings[0][i] == '?')
                res[i] = i == 0 ? '1' : '0';
    }
    for (int i = 1;i < n;++i) {
        auto& str = strings[i];
        auto& prestr = ans[i - 1];
        auto& res = ans[i] = str;
        int sz = str.length();
        if (str.length() < prestr.length()) {
            std::cout << "NO";
            return 0;
        }
        if (str.length() > prestr.length()) {
            for (int i = sz - 1;i >= 0;--i)
                if (str[i] == '?')
                    res[i] = i == 0 ? '1' : '0';
            continue;
        }
        bool f;
        int pos = -1;
        for (int i = 0;i < sz;++i) {
            if (str[i] == '?') {
                if (prestr[i] != '9')
                    pos = i;
                f = true;
            }
            else if (str[i] > prestr[i]) {
                pos = i;
                f = false;
                break;
            }
            else if (str[i] < prestr[i])
                break;
        }
        if (~pos) {
            if (f) res[pos] = prestr[pos] + 1;
            for (int i = 0;i < pos;++i)if (str[i] == '?')
                res[i] = prestr[i];
            for (int i = pos + 1;i < sz;++i)if (str[i] == '?')
                res[i] = '0';
        }
        else {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES\n";
    for (auto& str : ans)std::cout << str << '\n';
    return 0;
}