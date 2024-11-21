#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

#define int long long

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
    int n, m, q;std::cin >> n >> m >> q;
    std::vector<int> open(n + 1);
    std::set<i64> st;
    std::vector<i64> res(m + 1);
    int now = -1;
    for (int i = 0;i < q;++i) {
        int op;std::cin >> op;
        if (op == 1) {
            int x;std::cin >> x;
            open[x] = m;
            now = x;
            st.clear();
        }
        if (op == 2 || op == 3) {
            int id, x;std::cin >> id >> x;
            if (x != now)continue;
            if (st.count(id))continue;
            st.insert(id);
            if (op == 2) {
                res[id] += open[x];
                open[x]--;
            }
        }
    }
    std::vector<int> id(m + 1);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin() + 1, id.end(), [&](int x, int y) {
        if (res[x] == res[y])return x < y;
        return res[x] > res[y];
        });
    for (int i = 1;i <= m;++i) {
        std::cout << id[i] << ' ' << res[id[i]] << '\n';
    }
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