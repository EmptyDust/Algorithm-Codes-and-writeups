#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    std::vector<i64> a(6);
    for (int i = 1;i <= 5;++i)std::cin >> a[i];
    i64 ans = 0;
    //51
    {
        auto c = std::min(a[5], a[1]);
        a[1] -= c;
        a[5] -= c;
        ans += c;
    }
    //42
    {
        auto c = std::min(a[4], a[2]);
        a[2] -= c;
        a[4] -= c;
        ans += c;
    }
    //411
    {
        auto c = std::min(a[4], a[1] / 2);
        a[1] -= c * 2;
        a[4] -= c;
        ans += c;
    }
    //33
    {
        auto c = a[3] / 2;
        a[3] -= c * 2;
        ans += c;
    }
    //321
    {
        auto c = std::min({ a[3],a[2],a[1] });
        a[1] -= c;
        a[2] -= c;
        a[3] -= c;
        ans += c;
    }
    //3111
    {
        auto c = std::min(a[3], a[1] / 3);
        a[1] -= c * 3;
        a[4] -= c;
        ans += c;
    }
    //222
    {
        auto c = a[2] / 3;
        a[2] -= c * 3;
        ans += c;
    }
    //2211
    {
        auto c = std::min(a[2] / 2, a[1] / 2);
        a[1] -= c * 2;
        a[2] -= c * 2;
        ans += c;
    }
    //21111
    {
        auto c = std::min(a[2], a[1] / 4);
        a[1] -= c * 4;
        a[2] -= c;
        ans += c;
    }
    //111111
    {
        auto c = a[1] / 6;
        a[1] -= c * 6;
        ans += c;
    }


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