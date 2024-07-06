#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, int>;
using int_rb_tree = tree<pii, null_type, std::less<pii>, rb_tree_tag, tree_order_statistics_node_update>;
i64 n, a[MAXN], is_z[MAXN], z_child[MAXN], s_child[MAXN], cj[MAXN];
std::vector<int> adj[MAXN];

pii dfs1(int x, i64 sum) {
    i64 child_sum = 0, zhic_sum = 0;
    for (int nxt : adj[x]) {
        auto [c_sum, z_sum] = dfs1(nxt, sum + a[x]);
        child_sum += c_sum;
        zhic_sum += z_sum;
    }
    if (child_sum <= a[x] && a[x] <= sum)zhic_sum++, is_z[x] = 1;
    else if (a[x] <= sum && x) {
        cj[x] = child_sum - a[x];
    }
    z_child[x] = zhic_sum;
    s_child[x] = child_sum;
    return { child_sum + a[x],zhic_sum };
}

i64 ans = 0, t = 0;
int_rb_tree rbtree;
void dfs2(int x, i64 sum) {
    int curt = t++;
    ans = std::max(ans, (i64)rbtree.order_of_key({ s_child[x] + a[x],curt }) + z_child[0] - z_child[x]);
    if (cj[x])
        rbtree.insert({ cj[x],curt });//, std::cout << x << ' ' << cj[x] << '#';
    //std::cout << x << " " << s_child[x] + a[x] << ' ' << ans << '\n';
    for (int nxt : adj[x]) {
        dfs2(nxt, sum + a[x]);
    }
    if (cj[x])
        rbtree.erase({ cj[x],curt });
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int i = 1;i <= n;++i) {
        int fa;std::cin >> fa;
        adj[fa].push_back(i);
    }
    dfs1(0, 0);
    ans = z_child[0];
    dfs2(0, 0);
    std::cout << ans;
    return 0;
}