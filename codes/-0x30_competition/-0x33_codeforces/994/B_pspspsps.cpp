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

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    bool a = 0;
    for (char ch : s) {
        if (ch == 'p')a = 1;
        else if (ch == 's' && a) {
            std::cout << "NO";
            return;
        }
    }
    if (std::count(s.begin(), s.end(), 'p') == 0 || std::count(s.begin(), s.end(), 's') == 0) {
        std::cout << "YES";
        return;
    }
    if (std::count(s.begin(), s.end(), 'p') == 1 && s.back() == 'p' ||
        std::count(s.begin(), s.end(), 's') == 1 && s.front() == 's') {
        std::cout << "YES";
        return;
    }
    std::cout << "NO";
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