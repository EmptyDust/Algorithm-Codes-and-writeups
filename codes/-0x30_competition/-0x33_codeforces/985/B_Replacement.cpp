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
    std::string t;std::cin >> t;
    int cnt0 = std::count(s.begin(), s.end(), '0');
    int cnt1 = std::count(s.begin(), s.end(), '1');
    for (int i = 0;i < n - 1;++i) {
        if (cnt0 == 0 || cnt1 == 0) {
            std::cout << "NO";
            return;
        }
        int c = t[i] - '0';
        cnt0--, cnt1--;
        if (c)cnt1++;
        else cnt0++;
    }
    std::cout << "YES";
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