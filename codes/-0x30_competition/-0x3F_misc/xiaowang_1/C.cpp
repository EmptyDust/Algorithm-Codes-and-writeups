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
    std::string s;std::cin >> s;
    int cntc = 0, cntz = 0;
    i64 min = 0, cur = 0;
    for (char ch : s) {
        switch (ch)
        {
        case 'c':
            cntc++;
            break;
        case 'f':
            cur += cntc;
            break;
        case 'z':
            cntz++;
            break;
        case 'y':
            cur -= cntz;
            break;
        }
        min = std::min(min, cur);
    }
    if (min >= 0) std::cout << "YES";
    else {
        std::cout << "NO\n" << -min;
    }
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