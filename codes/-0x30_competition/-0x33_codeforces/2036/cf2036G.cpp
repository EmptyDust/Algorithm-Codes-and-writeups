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

i64 n;

i64 query(i64 l, i64 r){
    l = std::max(l, 1ll);
    r = std::min(n, r - 1);
    if (l > r)return 0;
    std::cout << "xor " << l << ' ' << r << std::endl;
    i64 rs;std::cin >> rs;
    return rs;
}

void solve() {
    std::cin >> n;
    std::vector<i64> ans;
    i64 l = 0, r = 1ll << 60, d = 60;;
    // std::cout << l << ' ' << (r > 1e18) << '\n';
    while (1){
        auto mid = l + r >> 1;
        i64 x = query(l, mid);
        i64 y = query(mid, r);
        d--;
        if (!y){
            r = mid;
        }
        else if (!x){
            l = mid;
        }
        else if (y >> d & 1){
            ans.push_back(y);
            r = mid;
            break;
        }
        else {
            ans.push_back(x);
            l = mid;
            break;
        }
    }


    while (1){
        auto mid = l + r >> 1;
        i64 x = query(l, mid);
        i64 y = query(mid, r);
        d--;
        if (!y)r = mid;
        else if (!x){
            l = mid;
        }
        else{
            ans.push_back(x);
            ans.push_back(y);
            break;
        }
    }
    ranges::sort(ans);
    std::cout << "ans ";
    for (int i = 0;i < 3;++i){
        std::cout << ans[i];
        if (i < 2)std::cout << ' ';
    }
    std::cout << std::endl;
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