#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    std::string s;std::cin >> s;
    i64 ans = 0;
    std::vector<int> wa(2, -1), accept(6, -1);
    for (int i = 0;i < n;++i) {
        switch (s[i])
        {
        case 'A':
            accept[0] = i;
            wa[1] = wa[0];
            break;
        case 'C':
            accept[2] = accept[1];
            accept[1] = accept[0];
            break;
        case 'E':
            accept[3] = accept[2];
            break;
        case 'P':
            accept[4] = accept[3];
            break;
        case 'T':
            accept[5] = accept[4];
            break;
        case 'W':
            wa[0] = i;
            break;
        }
        int ac_len = i - accept[5] + 1;
        int wa_len = i - wa[1] + 1;
        ac_len = std::max(ac_len, k);
        if (ac_len < wa_len)ans += wa_len - ac_len;
    }
    std::cout << ans;
    return 0;
}