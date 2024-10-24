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

std::vector<int> get_y(int c){
    std::vector<int> res;
    for (int i = 2;i <= std::sqrt(c);++i){
        while (c % i == 0){
            res.push_back(i);
            c /= i;
        }
    }
    res.push_back(c);
    return res;
}

void solve() {
    int a, b;std::cin >> a >> b;
    if (a > b)std::swap(a, b);
    int c = b - a;
    auto y = get_y(c);
    int ans = a - 1;
    std::map<int, int> vis;
    do
    {
        int U = a, D = a;
        int dU = 0, dD = 0;
        // for (int x : y)std::cout << x << ' ';std::cout << '\n';
        for (int x : y){
            if (U % x == 0){
                dU += 1;
                U = U / x;
            }
            else{
                dU += (U / x + 1) * x - U + 1;
                U = U / x + 1;
            }
            dD += D - D / x * x + 1;
            D = D / x;
            dU = std::min(dU, dD + 1);
            dD = std::min(dD, dU + 1);
            ans = std::min({ ans,dD + D - 1,dU + U - 1 });
            // std::cout << U << " " << D << '\n';
            if (D == 1)break;
        }
    } while (std::next_permutation(y.begin(), y.end()));
    std::cout << ans << '\n';
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