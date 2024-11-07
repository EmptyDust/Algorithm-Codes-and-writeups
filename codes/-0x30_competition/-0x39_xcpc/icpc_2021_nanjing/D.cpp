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

int cal(std::vector<int> a){
    int n = a.size();
    i64 ans = 0;
    for (int& x : a)std::cin >> x;
    for (int i = 0;i < n;++i){
        for (int j = 0;j < n;++j){
            if (a[i] < a[j]){
                std::swap(a[i], a[j]);
                ans++;
            }
        }
        //for (int x : a)std::cout << x << ' ';std::cout << '\n';
    }
    return ans;
}

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    for (int i = 1;i <= n;++i){
        std::vector<int> b;
        for (int j = 0;j < i;++j)b.push_back(a[j]);
        std::cout << cal(b) << ' ';
    }
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