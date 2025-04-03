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
    std::string s = "20250103";
    std::map<char, int> mp;
    for (char ch : s)mp[ch - '0']++;
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    for (int i = 0;i < n;++i) {
        mp[a[i]]--;
        bool ok = true;
        for (auto [num, cnt] : mp) {
            if (cnt > 0)ok = false;
            // std::cout << cnt << ' ';
        }
        // std::cout << '\n';
        if (ok) {
            std::cout << i + 1;
            return;
        }
    }
    std::cout << 0;
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