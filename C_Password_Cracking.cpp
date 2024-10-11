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
int n;
bool query(std::string s) {
    if (s.length() > n)return 0;
    std::cout << "? " << s << std::endl;
    int t;std::cin >> t;
    return t;
}

void ans(std::string s) {
    std::cout << "! " << s << std::endl;
}

void solve() {
    std::cin >> n;
    if (n == 1) {
        if (query("1")) {
            ans("1");
        }
        else ans("0");
        return;
    }
    if (n == 2) {
        std::string s[4] = { "10","01","00","11" };
        for (auto x : s) {
            if (query(x)) {
                ans(x);
                return;
            }
        }
    }
    std::string s = "0";
    if (!query(s)) {
        ans(std::string(n, '1'));
        return;
    }
    while (s.length() < n) {
        s += "0";
        if (!query(s)) {
            s.pop_back();
            break;
        }
    }
    if (n == s.length()) {
        ans(s);
        return;
    }
    while (1) {
        if (query(s + '1')) {
            s += '1';
            continue;
        }
        else if (query(s + '0')) {
            s += '0';
            continue;
        }
        else break;
    }
    if (n == s.length()) {
        ans(s);
        return;
    }
    while (1) {
        if (query('1' + s)) {
            s = '1' + s;
            continue;
        }
        else if (query('0' + s)) {
            s = '0' + s;
            continue;
        }
        else break;
    }
    ans(s);
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}