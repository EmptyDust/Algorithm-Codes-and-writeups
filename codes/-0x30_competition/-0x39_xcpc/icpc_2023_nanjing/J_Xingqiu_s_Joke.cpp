#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector<int> get_py(int c){
    std::vector<int> res;
    for (int i = 2;i <= std::sqrt(c);++i){
        if (c % i == 0)
            res.push_back(i);
        while (c % i == 0){
            c /= i;
        }
    }
    if (c != 1)
        res.push_back(c);
    res.push_back(1);
    return res;
}

std::vector<int> get_y(int c){
    std::vector<int> res;
    for (int i = 1;i <= std::sqrt(c);++i){
        if (c % i == 0){
            res.push_back(i);
            if (i != c / i)
                res.push_back(c / i);
        }
    }
    ranges::sort(res);
    ranges::reverse(res);
    return res;
}

int cal(std::vector<int> y){
    return std::unique(y.begin(), y.end()) - y.begin();
}

void solve() {
    int a, b;std::cin >> a >> b;
    if (a > b)std::swap(a, b);
    int c = b - a;
    auto py = get_py(c);
    auto y = get_y(c);
    int sz = y.size();
    // std::cout << sz << '\n';
    // for (int x : y)std::cout << x << ' ';
    std::map<int, int> pos;
    for (int i = 0;i < sz;++i)pos[y[i]] = i;

    std::vector dp(y.size(), std::map<int, int>());
    dp[0][a] = 0;

    int ans = a - 1;
    for (int i = 0;i < sz;++i){
        for (int x : py)if (y[i] % x == 0){
            int j = pos[y[i] / x];
            for (auto [num, dis] : dp[i]){
                ans = std::min(ans, dis + num - 1);
                if (x == 1)continue;
                int U = num, D = num;
                int dU = dis, dD = dis;
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
                if (dp[j].count(U)){
                    dp[j][U] = std::min(dp[j][U], dU);
                }
                else dp[j][U] = dU;
                if (dp[j].count(D)){
                    dp[j][D] = std::min(dp[j][D], dD);
                }
                else dp[j][D] = dD;
            }
        }
    }
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