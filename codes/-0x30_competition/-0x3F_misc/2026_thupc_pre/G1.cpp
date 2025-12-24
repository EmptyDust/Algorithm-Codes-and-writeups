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

int n;
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
    while (ans.size() < n + 5) ans.push_back('0');
    ranges::reverse(ans);
    return ans;
}

void solve() {
    std::cin >> n;
    std::string s;std::cin >> s;
    ranges::reverse(s);
    while (s.size() && s.back() == '0') s.pop_back();
    n = s.size();
    if (n == 0) {
        std::cout << 0;
        return;
    }
    auto ans = std::min(add(s.substr(0, n / 2), s.substr(n / 2, n - n / 2)),
        add(s.substr(0, n - n / 2), s.substr(n - n / 2, n / 2)));
    // std::cout << ans << '\n';
    int mid = n / 2;
    while (mid < n && s[mid] == '0') mid++;
    // std::cout << mid << "\n";
    // std::cout << s.substr(0, mid) << ' ' << s.substr(mid, n - mid) << '\n';
    // std::cout << add(s.substr(0, mid), s.substr(mid, n - mid)) << '\n';
    ans = std::min(ans, add(s.substr(0, mid), s.substr(mid, n - mid)));
    ranges::reverse(ans);
    while (ans.size() && ans.back() == '0') ans.pop_back();
    ranges::reverse(ans);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    // std::cout << add("10", "1");
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}