#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    std::vector<int> fx(n, 0);
    for (int i = 1;i < n;++i) {
        fx[i] = fx[i - 1] + (s[i] != s[i - 1]);
    }
    std::vector<int> fy(n, 0);
    for (int i = 2;i < n;i++) {
        fy[i] = fy[i - 2] + (s[i] != s[i - 2]);
    }

    std::vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    std::vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : std::min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }

    int l, r;
    while (q--) {
        std::cin >> l >> r;
        l--, r--;
        int len = r - l + 1;
        i64 ans = 0;
        if (fx[l] == fx[r]) {
            ans = 0;
        }
        else if (len == 1 || len % 2 == 1 && fy[r] == fy[l] && fy[r - 1] == fy[l + 1]) {
            ans = 1ll * (len - 1 + 2) * (len / 2) / 2;
        }
        else if (len % 2 == 0 && fy[r] == fy[l + 1] && fy[r - 1] == fy[l]) {
            ans = 1ll * (len + 2) * (len / 2) / 2;
        }
        else {
            ans = 1ll * (2 + len) * (len - 1) / 2;
            if (len % 2 && d1[(r + l) / 2] * 2 - 1 >= len) {
                ans -= len;
            }
            if (len % 2 == 0 && d2[(r + l) / 2 + 1] * 2 >= len) {
                ans -= len;
            }
        }
        std::cout << ans << '\n';
    }
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