#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;
using a9 = std::array<int, 9>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e5 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;


using pvv = std::pair < std::vector<int>, std::vector<int>>;
std::vector<pvv> all;

std::vector<int> cnt(9);
std::vector<int> fac(9);

void dfs(int cur) {
    if (cur == 9 - 2) {
        std::vector<int> real(8 + 1), mod3(8 + 1);
        for (int i = 1;i <= 8 - 2;i++)
        {
            real[i] += cnt[i];
            real[i + 1] += cnt[i];
            real[i + 2] += cnt[i];
        }
        for (int i = 1;i <= 8;i++)
            mod3[i] = real[i] % 3;

        all.push_back({ real,mod3 });
        return;
    }
    for (int i = 0;i < 3;i++) {
        cnt[cur] = i;
        dfs(cur + 1);
    }
}

/*

1. f(r,k) - f(l - 1,k) >= p.real[x];
2. f(r,k) % 3 == (f(l,k) + p.mod3[x]) % 3;

*/

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];

    std::vector<a9> pre(n + 1);
    std::vector first_l(9, std::vector<int>(n + 2));

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= 8;j++) pre[i][j] = pre[i - 1][j];
        first_l[a[i]][pre[i][a[i]]] = i - 1;
        pre[i][a[i]]++;
    }

    for (int i = 1;i <= 8;i++)
        first_l[i][pre[n][i]] = n;

    auto hash = [&](a9& v) {
        int res = 0;
        for (int i = 1;i <= 8;i++) res += v[i] * fac[i - 1];
        return res;
        };

    i64 ans = 0;
    for (auto& [real, mod3] : all) {

        std::vector<std::vector<int>> pos_q(n + 1);
        a9 cur = pre[n];
        a9 rmod3, lmod3;
        for (int i = 1;i <= 8;i++) rmod3[i] = cur[i] % 3;
        for (int i = 1;i <= 8;i++)  lmod3[i] = (rmod3[i] - mod3[i] + 3) % 3;

        int hs = hash(lmod3);

        int l_pos = n;
        int f = 1;
        for (int i = 1; i <= 8; i++) {
            if (cur[i] < real[i]) {
                f = 0;
                break;
            }
            l_pos = std::min(l_pos, first_l[i][cur[i] - real[i]]);
        }

        for (int i = n; i >= 1; i--) {
            if (!f) break;
            pos_q[std::min(l_pos, i - 1)].push_back(hs);

            int card = a[i];
            cur[card]--;

            rmod3[card] = (rmod3[card] - 1 + 3) % 3;
            lmod3[card] = (rmod3[card] - mod3[card] + 3) % 3;
            hs = hash(lmod3);

            if (cur[card] < real[card])
                f = 0;
            else
                l_pos = std::min(l_pos, first_l[card][cur[card] - real[card]]);
        }

        std::vector<int> hash_(fac[8], 0);
        a9 curmod3{};
        hash_[0]++;

        for (int hs : pos_q[0]) ans += hash_[hs];

        for (int i = 1; i <= n; i++) {
            curmod3[a[i]] = (curmod3[a[i]] + 1) % 3;
            hash_[hash(curmod3)]++;

            if (!pos_q[i].empty()) {
                for (int hs : pos_q[i]) {
                    ans += hash_[hs];
                }
            }
        }
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    dfs(1);
    int t = 1;
    std::cin >> t;

    for (int i = 0, j = 1;i <= 8;i++, j *= 3) fac[i] = j;

    while (t--) {
        solve();
        std::cout << '\n';
    }
}