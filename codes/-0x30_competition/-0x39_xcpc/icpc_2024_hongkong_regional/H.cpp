#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1'679'616;
const int MAXN = 1'679'616 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector vaild(6561, std::vector<int>(256)), cnt(6561, std::vector<int>(256));

std::vector<int> add(8);

std::vector<a2> val;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x, x--;
    std::vector<a3> cur;
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        std::vector<a3> ncur;
        ncur.push_back({ add[a[i]], 0, 1 });
        cnt[add[a[i]]][0] += 1;
        for (auto [x, y, c] : cur) {
            int sta = x / add[a[i]] % 3;
            x -= sta * add[a[i]];
            sta = (sta + 1) % 3;
            if (sta == 0) y |= 1 << a[i];
            x += sta * add[a[i]];
            ncur.push_back({ x, y, c });
            cnt[x][y] += c;
        }
        cur.clear();
        for (auto [x, y, c] : ncur) {
            // std::cout << x << ' ' << y << ' ' << c << '\n';
            if (cnt[x][y]) {
                if (vaild[x][y]) ans += cnt[x][y];
                cur.push_back({ x,y,cnt[x][y] });
                cnt[x][y] = 0;
            }
        }
        // std::cout << '\n';
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    for (int i = 0, j = 1;i < 8;++i, j *= 3) add[i] = j;//, std::cout << i << ' ' << add[i] << '\n';
    for (int j = 0;j < 256;++j) {
        vaild[0][j] = 1;
        val.push_back({ 0, j });
        for (int i = 1;i < 6561;++i) {
            std::array<int, 8> status = std::array<int, 8>();
            int last = -1;

            for (int k = 0, x = i;k < 8;++k) {
                status[k] = x % 3;
                x /= 3;
                if (j >> k & 1) status[k] += 3;
                if (status[k]) last = k;
            }
            for (int k = 0;k < 8;++k)
                if (j >> k & 1)
                    if (vaild[i][j ^ (1 << k)])
                        vaild[i][j] = 1;
            if (last >= 2 && status[last - 1] && status[last - 2]) {
                int ni = i;
                int nj = j;
                for (int k = last - 2;k <= last;++k) {
                    if (status[k] == 3) nj ^= 1 << k;
                    if (status[k] % 3)ni -= add[k];
                    else ni += 2 * add[k];
                }
                // assert(ni < 6561 && ni >= 0);
                // assert(nj < 256 && nj >= 0);
                // assert(i < 6561);
                // assert(j < 256);
                // std::cout << ni << ' ' << nj << '\n';
                if (vaild[ni][nj]) vaild[i][j] = 1;
            }
            // bool f = vaild[i][j];
            // if ((j >> 0 & 1) || (j >> 7 & 1))f = 0;
            // for (int k = 0;k < 8;++k) if (status[k] == 5) f = 0;
            // if (f) val.push_back({ i,j });
        }
    }
    // for (auto x : val)std::cout << x << ' ';
    // std::cout << val.size() << '\n';
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}