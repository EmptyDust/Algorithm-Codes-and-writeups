#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

i64 Logn[MAXN], f[MAXN][21];
void initt() {
    Logn[1] = 0, Logn[2] = 1;
    for (int i = 3; i < MAXN; ++i)
        Logn[i] = Logn[i / 2] + 1;
}

void init(std::vector<i64>& vt) {
    for (int i = 0;i < n;++i)
        f[i][0] = vt[i];
    for (int j = 1; j < 21; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

i64 query(int x, int y) {
    int s = Logn[y - x + 1];
    return std::max(f[x][s], f[y - (1 << s) + 1][s]);
}

void solve() {
    std::string s;std::cin >> s;
    std::map<int, i64> mp, tj;
    n = s.length();
    std::vector<i64> f(n);
    i64 cur = 0;
    for (int i = 0;i < n;++i)
        f[i] = cur += (s[i] == '(' ? 1 : -1);
    init(f);
    cur = 0;
    mp[0] = 0;
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        f[i] = cur += (s[i] == '(' ? 1 : -1);
        if (mp.count(cur)) {
            auto max = query(mp[cur] + 1, i);
            int rev = max - cur;
            if (max < cur || cur - rev >= 0) {
                ans += tj[cur];
                tj[cur]++;
            }
            else tj[cur] = 1;
        }
        else tj[cur] = 1;
        mp[cur] = i;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    initt();
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}