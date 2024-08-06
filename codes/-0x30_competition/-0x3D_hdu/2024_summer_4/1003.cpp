#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 2e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

const int N = 2e6;
int p[MAXN];
void init() {
    p[1] = 1;
    for (i64 i = 2;i <= N;++i)if (!p[i]) {
        for (i64 j = i * i;j <= N;j += i) {
            p[j] = 1;
        }
    }
}
//20 * 2 * 10 ^ 6 * 300
void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n + 1), s(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    if (k * 2 > n) {
        std::cout << "impossible";
        return;
    }
    for (int i = 1;i <= n;++i) {
        s[i] = s[i - 1] + a[i];
    }
    i64 l = 0, r = inf * 2;
    auto check = [&](auto x)->bool {
        int cnt = 0, pre = 0;
        std::set<pii> st;
        for (int i = 0;i <= n;++i) {
            // std::cout << i << ' ';
            for (auto [num, pos] : st) {
                if (!p[i - pos]) {
                    if (s[i] - num >= x) {
                        cnt++;
                        st.clear();
                    }
                    break;
                }
            }
            st.insert({ s[i],i });
            // for (int& p : primes) {
            //     if (i - p < pre)break;
            //     int m = s[i] - s[i - p];
            //     // if (i == 3)std::cout << m << ' ';
            //     if (m >= x) {
            //         cnt++;
            //         pre = i;
            //         break;
            //     }
            // }
        }
        return cnt >= k;
        };
    // std::cout << check(-9) << '\n';
    i64 ans = -inf;
    while (l <= r) {
        i64 mid = l + r >> 1;
        if (check(mid - inf)) {
            // std::cout << mid - inf << " ";
            ans = mid - inf;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    // std::cout << std::__lg((int)1e6) << ' ';
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}
