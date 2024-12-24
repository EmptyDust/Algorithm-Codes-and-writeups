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
    std::string s;std::cin >> s;
    int cnt3 = 0, cnt1 = 0, sum = 0;
    for (auto& ch : s) {
        int c = ch - '0';
        if (c == 2)cnt1++;
        if (c == 3)cnt3++;
        sum += c;sum %= 9;
    }
    sum = (9 - sum) % 9;
    if (sum & 1)sum += 9;
    sum /= 2;
    sum -= std::min(sum / 3, cnt3) * 3;
    return sum <= cnt1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << (solve() ? "YES" : "NO");
        std::cout << '\n';
    }
    return 0;
}