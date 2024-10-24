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
    int n, m;std::cin >> n >> m;
    std::vector _info(n, std::vector<int>());
    for (auto& vt : _info){
        int k;std::cin >> k;
        vt.resize(k);
        for (int& x : vt)std::cin >> x;
    }
    std::set<int> exist;
    std::vector del(n, std::vector<int>());
    std::vector info(n, std::vector<int>());
    for (int i = n - 1;i >= 0;--i){
        for (int x : del[i])exist.insert(x);del[i].clear();
        for (int x : _info[i]){
            if (!exist.count(x)){
                info[i].push_back(x);
                if (i >= 2)
                    del[i - 2].push_back(x);
            }
        }
    }

    std::set<int> st;
    bool ans = false;
    std::vector<int> res(n);
    std::iota(res.begin(), res.end(), 1);
    for (int i = 0;i < n;++i){
        std::set<int> nst;
        bool ok = true;
        for (int x : info[i]){
            if (st.count(x))ok = false;
            nst.insert(x);
        }
        if (ans)continue;
        if (i && ok){
            ans = true;
            std::swap(res[i], res[i - 1]);
        }
        st = nst;
    }
    std::cout << (ans ? "Yes" : "No") << '\n';
    if (ans){
        for (int i = 0;i < n;++i){
            std::cout << res[i] << " \n"[i == n - 1];
        }
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