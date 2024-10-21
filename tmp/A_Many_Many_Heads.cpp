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

bool solve() {
    std::string s, t;std::cin >> s;t.reserve(s.length());
    int n = s.length();
    for (char ch : s){
        if (ch == '[' || ch == ']')t += '1';
        else t += '0';
    }
    int cnt = 0;
    for (int i = 0;i < n - 1;++i){
        if (t[i] == t[i + 1])
            cnt++;
    }
    return cnt <= 2;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << (solve() ? "Yes" : "No");
        std::cout << '\n';
    }
    return 0;
}