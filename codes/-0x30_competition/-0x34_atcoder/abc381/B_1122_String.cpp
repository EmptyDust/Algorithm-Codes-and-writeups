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
    if (s.length() % 2) {
        std::cout << "No";
        return;
    }
    std::set<char> st;
    bool ok = true;
    for (int i = 0;i < s.length() / 2;++i) {
        if (s[i * 2] != s[i * 2 + 1]) ok = false;
        if (st.count(s[i * 2])) ok = false;
        st.insert(s[i * 2]);
    }
    std::cout << (ok ? "Yes" : "No");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}