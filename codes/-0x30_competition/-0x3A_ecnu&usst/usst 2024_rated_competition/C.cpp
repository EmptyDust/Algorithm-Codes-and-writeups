#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;


bool check(std::string a, std::string b) {
    //std::cout << a << '\n' << b << '\n';
    if (a == b)return true;
    for (char& ch : a) {
        if (ch == '1')ch = '0';
        else ch = '1';
    }
    return a == b;
}

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    std::string t;std::cin >> t;
    std::vector<int> a(n);int c = 0;
    for (int i = 0;i < n;++i) {
        if (t[i] == '1')c++;
        else c--;
        a[i] = c;
    }
    c = 0;
    int cur = 0;
    for (int i = 0;i < n;++i) {
        if (s[i] == '1')c++;
        else c--;
        if (c == 0) {
            if (!check(s.substr(cur, i - cur + 1), t.substr(cur, i - cur + 1))) {
                std::cout << "NO";
                return;
            }
            cur = i + 1;
        }
    }
    if (cur >= n || s.substr(cur) == t.substr(cur)) {
        std::cout << "YES";
    }
    else std::cout << "NO";
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