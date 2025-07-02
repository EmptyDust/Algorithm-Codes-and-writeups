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

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<a3> info(n);
    for (auto& [x, _, _] : info)std::cin >> x;
    for (auto& [_, y, _] : info)std::cin >> y;
    for (int i = 0;i < n;++i)info[i][2] = i;
    std::vector<a3> vaild(n);
    std::set<a3> st;
    for (int i = 0;i < n;++i) {
        if (st.contains(info[i])) {
            auto it = st.lower_bound(info[i]);
            vaild[(*it)[2]][1] = i;
            st.erase(it);
            st.insert(info[i]);
        }
        else {
            do{
                auto it = st.upper_bound()
            }
        }

    }
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