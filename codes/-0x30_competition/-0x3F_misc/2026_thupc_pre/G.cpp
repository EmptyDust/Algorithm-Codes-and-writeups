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

std::string add(std::string a, std::string b) {
    std::string ans;
    int c = 0;
    for (int i = 0;i < std::max(a.length(), b.length());++i) {
        if (i < a.size() && a[i] == '1') c++;
        if (i < b.size() && b[i] == '1') c++;
        ans += char('0' + c % 2);
        c /= 2;
    }
    if (c) ans += char('0' + c % 2);
    ranges::reverse(ans);
    return ans;
}

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    ranges::reverse(s);
    int c = ranges::count(s, '1');
    if (c == 0) {
        std::cout << 0;
        return;
    }
    std::string t1, t2;
    for (int i = 0;i < n && c;++i) {
        t1 += s[i];
        if (s[i] == '1') c--;
        if (c) t2 += '1', c--;
        // std::cout << t1 << ' ' << t2 << '\n';
    }
    std::cout << add(t1, t2);
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