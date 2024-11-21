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
    int n;std::cin >> n;
    if (n == 6){
        std::cout << "7\n1 2 4 6 5 3 ";
        return;
    }
    std::vector<int> a(n + 1), ans;
    if (n % 2){
        ans.push_back(n);
        ans.push_back(n - 1);
        ans.push_back(3);
        ans.push_back(1);
    }
    else{
        ans.push_back(n);
        int m = (1 << std::__lg(n)) - 1;
        ans.push_back(m);
        ans.push_back(m - 1);
        ans.push_back(3);
        ans.push_back(1);
    }
    for (int x : ans)a[x] = 1;
    for (int i = 1;i <= n;++i)if (!a[i])ans.push_back(i);
    std::reverse(ans.begin(), ans.end());
    int k = 0;
    for (int i = 0;i < n;++i){
        if (i % 2){
            k |= ans[i];
        }
        else k &= ans[i];
    }
    std::cout << k << '\n';
    for (int x : ans)std::cout << x << ' ';
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