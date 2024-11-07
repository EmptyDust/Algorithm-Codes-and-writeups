#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;

#define ranges std::ranges
using i64 = long long;

using pii = std::pair<i64, i64>;
using int_rb_tree = tree<pii, null_type, std::less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

const i64 inf = 8e18;

void solve(){
    int n, m;std::cin >> n >> m;
    std::vector<int> a(n), pre(n);
    for (int& x : a)std::cin >> x;
    std::vector<pii> info(m);
    for (auto& [x, t] : info)std::cin >> x >> t, t--;
    ranges::sort(info);
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    int_rb_tree tree;
    tree.insert({ 0,sum });
    for (auto [x, t] : info){
        if (sum < x)break;
        i64 cap = a[t];
        while (cap){
            auto it = tree.upper_bound({ pre[t],inf });
            auto [st, len] = *it;
            if (st + len <= x)break;
            tree.erase(it);
            i64 u = std::min(x - st + len, )
        }
        pre[t] = x;
    }
    std::cout << sum;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--){
        solve();
        std::cout << '\n';
    }
    return 0;
}