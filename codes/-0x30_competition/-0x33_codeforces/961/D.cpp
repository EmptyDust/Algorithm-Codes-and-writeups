#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, c, k;std::cin >> n >> c >> k;
    std::string s;std::cin >> s;
    for (char& ch : s)ch -= 'A';
    int mask = 0;
    std::vector<int> charc(c), cnt(1 << c), tot(1 << c);
    for (int i = 0;i < k;++i) {
        mask |= 1 << s[i];
        charc[s[i]]++;
    }
    cnt[mask]++;
    for (int i = k;i < n;++i) {
        mask |= 1 << s[i];
        charc[s[i]]++;
        charc[s[i - k]]--;
        if (charc[s[i - k]] == 0) {
            mask ^= 1 << s[i - k];
        }
        cnt[mask]++;
    }
    cnt[1 << s[n - 1]]++;
    // for (int mask = 0;mask < 1 << c;++mask) {
    //     for (int submask = mask;submask;submask = (submask - 1) & mask) {
    //         tot[mask] += cnt[submask];
    //     }
    // }
    for (int mask = 0;mask < 1 << c;++mask)
        tot[mask] = cnt[mask];
    for (int s = 0;s < c;++s)
        for (int mask = 0;mask < 1 << c;++mask)
            if (mask >> s & 1)
                tot[mask] += tot[mask ^ (1 << s)];
    int ans = c;
    for (int mask = 0;mask < 1 << c;++mask) {
        if (tot[mask] == 0) {
            ans = std::min(ans, c - std::__popcount(mask));
        }
    }
    std::cout << ans;
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