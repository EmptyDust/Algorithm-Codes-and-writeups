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
    std::string s;std::cin >> s;
    std::vector<int> pcnto(26), pcnte(26), scnto(26), scnte(26);
    for (int i = 0;i < n;++i) {
        if (i % 2)scnto[s[i] - 'a']++;
        else scnte[s[i] - 'a']++;
    }
    if (n % 2 == 0) {
        int ans = 0;
        ans += n / 2 - *std::max_element(scnto.begin(), scnto.end());
        ans += n / 2 - *std::max_element(scnte.begin(), scnte.end());
        std::cout << ans;
    }
    else {
        int ans = inf;
        for (int i = 0;i < n;++i) {
            if (i % 2)scnto[s[i] - 'a']--;
            else scnte[s[i] - 'a']--;
            if (i) {
                if ((i - 1) % 2)pcnto[s[i - 1] - 'a']++;
                else pcnte[s[i - 1] - 'a']++;
            }
            std::vector<int> reso(26), rese(26);
            for (int i = 0;i < 26;++i) {
                reso[i] = scnte[i] + pcnto[i];
                rese[i] = scnto[i] + pcnte[i];
            }
            int res = 0;
            res += n / 2 - *std::max_element(reso.begin(), reso.end());
            res += n / 2 - *std::max_element(rese.begin(), rese.end());
            ans = std::min(ans, res);
            // std::cout << res << ' ';
        }
        std::cout << ans + 1;
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