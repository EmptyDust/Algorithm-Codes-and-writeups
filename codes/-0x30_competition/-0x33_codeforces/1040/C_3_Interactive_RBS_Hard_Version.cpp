#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

/*

1))22)))3333)))))

1))2)2))3)3)3))4)4)4)4)4))

1 3 6 15
*/

std::vector<int> sizes, minus;

void solve() {
    int n;std::cin >> n;
    auto ask1 = [&](int l, int r, bool re = 0) {
        std::cout << "? " << r - l + 1 << ' ';
        if (!re) for (int i = l;i <= r;++i) std::cout << i << ' ';
        else for (int i = r;i >= l;--i) std::cout << i << ' ';
        std::cout << std::endl;
        int x;std::cin >> x;
        return x;
        };
    int l = 1, r = n;
    bool re = 0;
    if (ask1(1, n) == 0) re = 1;
    while (l + 1 < r) {
        auto mid = l + r >> 1;
        if (ask1(l, mid, re))r = mid;
        else l = mid;
    }
    // assert(ask1(l, l + 1, re));
    int L = l;
    int R = l + 1;
    if (re) std::swap(L, R);
    std::vector<int> ans(n + 1, -1);
    std::vector<int> ask, now;
    int cur = 0;
    auto work = [&]() {
        assert(ask.size() <= 1000);
        std::cout << "? ";
        std::cout << ask.size() << ' ';
        for (int x : ask)std::cout << x << ' ';
        std::cout << std::endl;
        int res;std::cin >> res;
        for (int i = cur - 1;i >= 0;--i) {
            // std::cout << res << ' ' << sizes[i] << '\n';
            int x = now[i];
            if (res >= minus[i]) {
                ans[x] = 1;
                res -= minus[i];
            }
            else ans[x] = 0;
        }
        ask.clear();
        now.clear();
        cur = 0;
        };
    for (int i = 1;i <= n;++i) {
        if (cur == sizes.size()) {
            work();
        }
        now.push_back(i);
        for (int j = 0;j < sizes[cur];++j) {
            ask.push_back(i);
            ask.push_back(R);
        }
        // std::cout << cur << ' ' << sizes[cur] << '\n';
        ask.push_back(R);
        cur++;
    }
    work();
    std::cout << "! ";
    for (int i = 1;i <= n;++i)std::cout << (ans[i] ? '(' : ')');
    std::cout << std::endl;
}
// )))()())()()())
// 3 + 3 + 2 + 1 = 9
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int cur = 0, use = 0;
    for (int i = 1, sum = 1;use <= 1000;++i, sum += i) {
        if (use + i * 2 + 1 > 1000)break;
        if (sum > cur) {
            sizes.push_back(i);
            minus.push_back(sum);
            // if (i == 3)std::cout << sum << ' ' << cur << '\n';
            cur += sum;
            use += i * 2 + 1;
            std::cout << i << ' ' << sum << ' ' << use << '\n';
        }
    }
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}