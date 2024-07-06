#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::set<int> st;
    for (int i = 0;i < n;++i) {
        int num;std::cin >> num;
        st.insert(num);
    }
    st.erase(st.begin());
    std::cout << *st.begin();
    return 0;
}
