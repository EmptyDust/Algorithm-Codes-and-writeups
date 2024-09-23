#include<bits/stdc++.h>

struct dsu
{
    std::vector<int> d;
    dsu(int n) { d.resize(n); std::iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (d[x] == x ? x : get_root(d[x])); }
    bool merge(int u, int v) {

    }
};


void solve() {
    int n;std::cin >> n;
    
}

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