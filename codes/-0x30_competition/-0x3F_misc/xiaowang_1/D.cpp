#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, w;std::cin >> n >> w;
    std::vector<i64> p(n), k(n);
    for (auto& x : p)std::cin >> x;
    for (auto& x : k)std::cin >> x;
    std::vector<int> q;
    for (int i = 0;i < n;++i) {
        while (q.size() && p[i] / w) {
            auto pos = q.back();
            i64& cnt = k[pos];
            i64 res = std::min(cnt, p[i] / w);
            p[i] -= res * w;
            cnt -= res;
            if (cnt == 0) q.pop_back();
        }
        q.push_back(i);
    }
    std::set<int> st;
    for (auto pos : q) {
        if (k[pos]) st.insert(pos);
        // std::cout << pos << '\n';
    }
    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&](int a, int b) {return p[a] > p[b];});
    for (auto i : idx) {
        auto it = st.lower_bound(i);
        // std::cout << i << ' ';
        if (it == st.begin()) continue;
        --it;
        auto pos = *it;
        i64& cnt = k[pos];
        // std::cout << pos << ' ' << i << '\n';
        i64 res = std::min(cnt, p[i] / w + 1);
        p[i] -= res * w;
        cnt -= res;
        st.erase(it);
        if (cnt) st.insert(pos);
    }
    i64 sum = 0;
    for (auto x : p)sum += std::max(0ll, x);
    std::cout << sum;
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