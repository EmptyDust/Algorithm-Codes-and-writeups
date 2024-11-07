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

//01010101

void solve() {
    std::string s;std::cin >> s;
    int cur = 0, cnt = 0;
    for (char ch : s){
        int x = ch - '0';
        if (x == 2){
            cur++;
            cnt++;
            continue;
        }
        if (x == ((cur % 2) + 2) % 2)cur++;
        else cur--;
    }
    if (cur <= 0)std::cout << std::abs(cur);
    else{
        cur -= std::min(cur / 2, cnt) * 2;
        std::cout << cur;
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