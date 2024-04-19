#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::set<std::string> st;
    std::string s;
    std::cin >> s;
    int n = s.length();
    for (int i = 0;i < n;++i) {
        for (int len = 1;len <= n - i;++len) {
            st.insert(s.substr(i, len));
        }
    }
    std::cout << st.size();

    return 0;
}