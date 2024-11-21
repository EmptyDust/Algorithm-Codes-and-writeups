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
    std::string s;std::cin >> s;
    int n = s.length();
    if (s[0] != '>' || s.substr(n - 3, 3) != ">>>" || std::count(s.begin(), s.end(), '-') == 0) {
        std::cout << "No\n";
        return;
    }
    int end = n - 3;
    std::vector<pii> ans;
    while (s[end] != '-') {
        ans.push_back({ 1,end + 3 });
        end--;
    }
    for (int i = 1;i < end;++i) {
        if (s[i] == '>')ans.push_back({ i + 1,end + 4 - i });
    }
    std::cout << "Yes " << ans.size() << '\n';
    for (auto [x, y] : ans)std::cout << x << ' ' << y << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}