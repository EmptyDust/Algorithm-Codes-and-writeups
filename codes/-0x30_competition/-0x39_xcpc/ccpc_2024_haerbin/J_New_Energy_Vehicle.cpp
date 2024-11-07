#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 2e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<i64> a(n + 1);
    for (int i = 1;i <= n;++i){
        std::cin >> a[i];
    }
    std::vector<pii> info(m);
    std::vector adj(n + 1, std::vector<i64>());
    for (auto& [x, t] : info){
        std::cin >> x >> t;
        adj[t].push_back(x);
    }
    std::set<a3> st;
    std::vector<i64> p(n + 1);
    for (int i = 1;i <= n;++i){
        adj[i].push_back(inf);
        // if (i == 2)std::cout << adj[i][1] << ' ';
        st.insert(a3{ adj[i][0],a[i],i });
    }
    i64 cur = 0;
    for (auto [x, t] : info){
        while (cur < x && st.size()){
            auto it = st.begin();
            auto [y, value, p] = *it;
            st.erase(it);
            if (y < x)continue;
            // std::cout << y << ' ' << value << ' ' << p << '\n';
            if (cur + value < x){
                cur += value;
            }
            else{
                value -= x - cur;
                cur = x;
                st.insert(a3{ y,value,p });
            }
        }
        if (cur < x)break;
        st.insert({ adj[t][++p[t]],a[t],t });
    }
    while (st.size()){
        auto it = st.begin();
        auto [y, value, _] = *it;
        st.erase(it);
        if (y != inf)continue;
        // std::cout << y << ' ' << value << ' ' << _ << '\n';
        cur += value;
    }
    std::cout << cur;
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