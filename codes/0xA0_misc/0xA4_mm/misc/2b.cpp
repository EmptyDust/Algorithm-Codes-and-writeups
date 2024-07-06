#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 998244353;
using i64 = long long;
int nums[MAXN];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;cin >> n;
    int cnt = 0, ans = 0;
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        int len = s.length();
        if (len == count(s.begin(), s.end(), '1')) {
            cnt += len;
        }
        else {
            {
                int c = 0;
                for (int i = 0;i < len;++i)
                    if (s[i] != '1') {
                        break;
                    }
                    else {
                        c++;
                    }
                ans = max(ans, c);
            }
            {
                int c = 0;
                for (int i = len - 1;i >= 0;--i)
                    if (s[i] != '1') {
                        break;
                    }
                    else {
                        c++;
                    }
                ans = max(ans, c);
            }
        }
    }
    cout << ans + cnt;
    return 0;
}