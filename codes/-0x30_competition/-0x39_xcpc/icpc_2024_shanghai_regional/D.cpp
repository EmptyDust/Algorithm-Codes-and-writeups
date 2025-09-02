#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
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
    int cur = 0;
    int cnt = ranges::count(s.substr(n - 2, 2), '1');
    for (int i = 0;i < n - 3;++i) {
        if (s[i] == '0') {
            if (cur) cur--;
        }
        else cur++;
    }
    if (cur > 1 || cnt == 0) {
        std::cout << "Yes";
        return;
    }
    if (cur == 0) {
        for (int i = 0;i < n - 4;++i) {
            if (s[i] == '0') {
                if (cur) cur--;
            }
            else cur++;
        }
        if (cur == 1 && s[n - 3] == '1') std::cout << "Yes";
        else std::cout << "No";
        return;
    }
    if (s.substr(n - 3, 3) == "001") {
        std::cout << "No";
    }
    else std::cout << "Yes";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}