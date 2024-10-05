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
    int n, a, b;std::cin >> n >> a >> b;
    std::vector<int> vt(n);
    for (int& x : vt)std::cin >> x;
    std::vector ans(a + 1, std::vector<int>(b + 1));
    for (int sum = 0;sum <= a + b;++sum) {
        int L = std::max(0, sum - b);
        int R = std::min(a, sum);
        int l = L, r = R;
        int suml = 0, sumr = 0;
        int len = R - L + 1;
        for (int& x : vt) {
            l -= x;
            r -= x;
            if (r > R) {
                if (l > R) {
                    sumr += len;
                    len = 0;
                    l = r = R;
                }
                else {
                    sumr += r - R;
                    len -= r - R;
                    r = R;
                }
            }
            if (l < L) {
                if (r < L) {
                    suml += len;
                    len = 0;
                    l = r = L;
                }
                else {
                    suml += L - l;
                    len -= L - l;
                    l = L;
                }
            }
        }
        // std::cout << L << ' ' << R << ' ' << suml << " " << sumr << '\n';
        for (int i = L;i < L + suml;++i) {
            ans[i][sum - i] = l;
            // std::cout << i << ' ' << sum - i << '\n';
        }
        for (int i = R;i > R - sumr;--i) {
            ans[i][sum - i] = r;
        }
        for (int i = L + suml, j = l;i <= R - sumr;++i, ++j) {
            ans[i][sum - i] = j;
        }
    }
    for (int i = 0;i <= a;++i) {
        for (int j = 0;j <= b;++j) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}