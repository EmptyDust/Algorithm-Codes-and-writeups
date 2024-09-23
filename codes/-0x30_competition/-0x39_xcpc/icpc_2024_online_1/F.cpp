#include<bits/stdc++.h>

using i64 = long long;
using a3 = std::array<int, 3>;

const int MAXN = 1e6 + 10;
const int N = 1e6;
//int rs[MAXN], ls[MAXN], stk[MAXN], p[MAXN];

// i64 ans = 0;
// void dfs(int l, int r, int i) {
//     if (l > r)return;
//     ans += r - l;
//     {
//         int x = i;
//         if (p[i] != -1)
//             dfs(p[i] + 1, i - 1, ls[i]);
//         else
//             dfs(l, i - 1, ls[i]);
//         while (p[i] != -1) {
//             x = p[i];

//         }
//     }
//     while (p[ls[i]])
//         dfs(i + 1, r, rs[i]);
// }

//  3 2 1 3 4

// struct dsu
// {
//     std::vector<int> d;
//     dsu(int n) { d.resize(n); std::iota(d.begin(), d.end(), 0); }
//     int get_root(int x) { return d[x] = (d[x] == x ? x : get_root(d[x])); }
//     bool merge(int u, int v) {

//     }
// };

void solve() {
    // ans = 0;
    int n;std::cin >> n;
    std::vector<int> a(n), pre(n, -1), suf(n, n);
    for (int& x : a)std::cin >> x;
    // std::priority_queue<a3> pq;
    // for (int i = 0;i < n;++i) {
    //     pq.push({ a[i],i - 1,i + 1 });
    // }
    // while (pq.size() > 1) {

    // }
    std::deque<int> dq;
    for (int i = 0;i < n;++i) {
        while (dq.size() && a[i] >= a[dq.back()])dq.pop_back();
        if (dq.size()) {
            pre[i] = dq.back();
        }
        dq.push_back(i);
    }
    dq.clear();
    for (int i = n - 1;i >= 0;--i) {
        while (dq.size() && a[i] >= a[dq.back()])dq.pop_back();
        if (dq.size()) {
            suf[i] = dq.back();
        }
        dq.push_back(i);
    }
    i64 ans = 0;
    std::map<int, int> r;
    for (int i = 0;i < n;++i) {
        if (!r.count(a[i]) || r.count(a[i]) && r[a[i]] < i) {
            ans += suf[i] - pre[i] - 2;
            r[a[i]] = suf[i];
        }
        else ans--;
        //        std::cout << suf[i] << ' ' << pre[i] << ' ' << ans << '\n';
    }
    std::cout << ans;
    // for (int i = 0;i < n;++i) {
    //     rs[i] = -1;
    //     ls[i] = -1;
    //     p[i] = -1;
    // }
    // int top = 0;
    // for (int i = 0;i < n;++i) {
    //     int k = top;
    //     while (k > 0 && a[stk[k - 1]] < a[i])k--;
    //     if (k > 0 && a[stk[k - 1]] == a[i]) {
    //         p[i] = stk[k - 1];
    //         k--;
    //     }
    //     if (k)rs[stk[k - 1]] = i;
    //     if (k < top)ls[i] = stk[k];
    //     stk[k++] = i;
    //     top = k;
    // }
    // dfs(0, n - 1, top);
    // std::cout << ans;
}
/*
4
2
1 2
2
2 2
7
1 1 1 2 2 2 2
3
1 2 3
*/
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}