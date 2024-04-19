#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 26;
int n, p[26], f[(int)1 << MAXN];
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::string s;
    std::vector<int> vec1(n), vec2(n);
    for (int i = 0;i < n;++i) {
        std::cin >> s;
        for (char& ch : s)vec1[i] ^= (int)1 << (ch - 'a'), vec2[i] |= (int)1 << (ch - 'a');
    }
    i64 ans = 0;
    for (int s = 0;s < 26;++s) {
        std::vector<int> v;
        for (int i = 0;i < n;++i) {
            if (vec2[i] >> s & 1)continue;
            v.push_back(vec1[i]);
            f[vec1[i]]++;
        }
        for (int num : v)ans += f[num ^ ((1 << 26) - 1) ^ (1 << s)];
        for (int num : v)f[num] = 0;
    }
    ans /= 2;
    std::cout << ans;
    return 0;
}