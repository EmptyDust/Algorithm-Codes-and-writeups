#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n;  std::cin >> n;
    std::string s;  std::cin >> s;
    s = " " + s;
    std::vector<int> a(n + 2);
    a[0] = a[n + 1] = -1;
    for (int i = 1;i <= n;i++)
    {
        if (s[i] == 'C') a[i] = 0;
        else if (s[i] == 'W') a[i] = 1;
        else a[i] = 2;
    }
    std::vector<a3> pre(n + 1);

    for (int i = 1;i <= n;i++)
    {
        pre[i] = pre[i - 1];
        pre[i][a[i]]++;
    }

    int L = n + 1, R = 0;
    for (int i = 1;i <= n;i++)
        if (a[i] == a[i - 1]) {
            L = i;
            break;
        }
    for (int i = n;i >= 1;i--) {
        if (a[i] == a[i + 1])
        {
            R = i;
            break;
        }
    }

    if (L > n) {
        std::cout << "Beautiful";
        return;
    }

    auto check = [&](int l, int r, a3 num) {
        // std::cout << l << ' ' << r << '\n';
        int limit0 = (r - l + 1 + 1 - (a[r + 1] == 0) - (a[l - 1] == 0)) / 2;
        int limit1 = (r - l + 1 + 1 - (a[r + 1] == 1) - (a[l - 1] == 1)) / 2;
        int limit2 = (r - l + 1 + 1 - (a[r + 1] == 2) - (a[l - 1] == 2)) / 2;
        if (num[0] > limit0 || num[1] > limit1 || num[2] > limit2) {
            return false;
        }
        return true;
        };

    int ans = inf, ansl = -1, ansr = -1;
    for (int r = R, l = 1;r <= n;) {
        a3 num;
        num[0] = pre[r][0] - pre[l - 1][0];
        num[1] = pre[r][1] - pre[l - 1][1];
        num[2] = pre[r][2] - pre[l - 1][2];
        // int len = r - l + 1;
        // int chl = a[l - 1], chr = a[r + 1];

        if (!check(l, r, num)) {
            r++;
            continue;
        }

        if (ans > (r - l + 1)) {
            ans = r - l + 1;
            ansl = l;
            ansr = r;
        }
        if (l == L) r++;
        l = std::min(l + 1, L);
    }

    if (ans == inf) {
        std::cout << "Impossible";
        return;
    }

    a3 num;
    num[0] = pre[ansr][0] - pre[ansl - 1][0];
    num[1] = pre[ansr][1] - pre[ansl - 1][1];
    num[2] = pre[ansr][2] - pre[ansl - 1][2];

    std::cout << "Possible\n";
    std::cout << ansl << ' ' << ansr << '\n';

    for (int i = ansl;i <= ansr;++i) {
        // std::cout << i << ' ' << num[0] << ' ' << num[1] << ' ' << num[2] << '\n';
        for (int j = 0;j < 3;++j) if (a[i - 1] != j && num[j]) {
            // if (i == 5)std::cout << j << ' ';
            a[i] = j;
            num[j]--;
            if (check(i + 1, ansr, num)) break;
            num[j]++;
        }
    }

    for (int i = 1;i <= n;i++)
    {
        if (a[i] == 0) std::cout << 'C';
        if (a[i] == 1) std::cout << 'W';
        if (a[i] == 2) std::cout << 'P';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}