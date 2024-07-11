#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    if (n == 2) {
        int a, b, c;std::cin >> a >> b >> c;
        std::cout << c;
        return 0;
    }
    std::vector<int> cnt(n), m(n);
    i64 sum = 0;
    for (int i = 0;i < n - 1;++i) {
        int a, b, c;std::cin >> a >> b >> c;a--, b--;
        if (!cnt[a])m[a] = c;
        if (!cnt[b])m[b] = c;
        sum += c * 2;
        cnt[a]++, cnt[b]++;
    }
    std::vector<int> max(2);
    for (int i = 0;i < n;++i)if (cnt[i] == 1) {
        int tmp = m[i];
        for (int j = 0;j < 2;++j) {
            if (tmp > max[j])std::swap(tmp, max[j]);
        }
    }
    sum -= max[0] + max[1];
    std::cout << sum;
    return 0;
}