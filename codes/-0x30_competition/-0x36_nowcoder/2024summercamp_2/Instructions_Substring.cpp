#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, x, y;std::cin >> n >> x >> y;
    std::string s;std::cin >> s;

    if (x == 0 && y == 0) {
        std::cout << 1ll * n * (n + 1) / 2;
        return 0;
    }

    std::map<pii, std::vector<int>> mp;
    mp[{0, 0}].push_back(0);

    std::vector<int> ans(n + 1, n + 1);
    int curx = 0, cury = 0;
    for (int i = 1;i <= n;++i) {
        char ch = s[i - 1];
        switch (ch)
        {
        case 'W':
            cury++;
            break;
        case 'S':
            cury--;
            break;
        case 'A':
            curx--;
            break;
        case 'D':
            curx++;
            break;
        }

        mp[{curx, cury}].push_back(i);

        pii ad = { curx - x,cury - y };
        for (int x : mp[ad])
            ans[x] = i;
        mp[ad].clear();
    }

    i64 res = 0;

    for (int i = 0;i <= n;++i) {
        res += n + 1 - ans[i];
    }

    std::cout << res;
    return 0;
}