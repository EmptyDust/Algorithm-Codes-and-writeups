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
const int mod = 1e9 + 7;
// const int mod = 998244353;

void solve() {
    int r, c;std::cin >> r >> c;
    std::vector set(c, std::vector<pii>());
    std::vector ss(r, std::string());
    for (int i = 0;i < r;++i){
        std::cin >> ss[i];
        for (int j = 0;j < c;++j)if (ss[i][j] == '1'){
            set[j].push_back({ i,1 });
            set[c - 1 - j].push_back({ i,0 });
        }
    }
    std::vector<pii> vis(c, { -1,-1 });
    std::queue<pii> q;
    i64 ans = 1;
    auto visit = [&](int id, pii p){
        // std::cout << id << '\n';
        if (vis[id] == p)return;
        if (vis[id] != pii{ -1, -1 }){
            ans = 0;
            return;
        }
        vis[id] = p;
        for (auto x : set[id])if (x != p){
            q.push({ x.first,!x.second });
        }
        };
    std::vector<int> st(r, -1);
    auto work = [&](int p, bool status){
        q.push({ p,status });
        while (ans && q.size()){
            auto [p, status] = q.front();
            q.pop();
            if (st[p] != -1){
                if (st[p] != status)
                    ans = 0;
                continue;
            }
            st[p] = status;
            for (int j = 0;j < c;++j)if (ss[p][j] == '1'){
                visit(status ? j : c - 1 - j, { p,status });
            }
        }
        };
    for (int i = 0;i < r && ans;++i){
        if (st[i] == -1){
            work(i, 1);
            ans = ans * 2 % mod;
        }
    }
    std::cout << ans;
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