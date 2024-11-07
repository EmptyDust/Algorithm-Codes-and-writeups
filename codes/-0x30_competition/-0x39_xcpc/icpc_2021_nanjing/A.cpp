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
    int a, b;std::cin >> a >> b;
    bool x = a <= (n + 1) / 2;
    bool y = b <= (n + 1) / 2;
    if (x && y){
        for (int i = 1;i < n;++i)std::cout << "LU";
        for (int i = 1;i < a;++i)std::cout << "D";
        for (int i = 1;i < b;++i)std::cout << "R";
    }
    else if (x){
        for (int i = 1;i < n;++i)std::cout << "RU";
        for (int i = 1;i < a;++i)std::cout << "D";
        for (int i = n;i > b;--i)std::cout << "L";
    }
    else if (y){
        for (int i = 1;i < n;++i)std::cout << "LD";
        for (int i = n;i > a;--i)std::cout << "U";
        for (int i = 1;i < b;++i)std::cout << "R";
    }
    else{
        for (int i = 1;i < n;++i)std::cout << "RD";
        for (int i = n;i > a;--i)std::cout << "U";
        for (int i = n;i > b;--i)std::cout << "L";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}