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

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::map<int, int> map;
void solve() {
    int n;std::cin >> n;
    auto it = --map.upper_bound(n);
    // std::cout << map[n] << ' ';
    auto [_, ans] = (*it);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::vector<int> cnt(10);
    auto cal = [&](int pos) {
        // if (cnt[9] && cnt[9] == cnt[0] && cnt[1] == 1) {
        //     bool ok = true;
        //     for (int i = 2;i <= 8;++i)if (cnt[i])ok = false;
        //     if (ok) {
        //         int res = 0;
        //         for (int i = 0;i < cnt[9];++i)res = res * 10 + 9;
        //         map[res]++;
        //         return res;
        //     }
        // }
        int min = inf;
        for (int c = 0;c <= std::min(cnt[9], cnt[0]);++c) {
            int last = -inf, last2 = -inf;
            bool ok = true;
            cnt[0] -= c;cnt[9] -= c;
            for (int i = 0;i < pos && ok;++i) {
                if (cnt[i] % 2) {
                    if (last == -inf)last = i, cnt[last]--;
                    else if (last2 == -inf) {
                        last2 = i, cnt[last2]--;
                    }
                    else {
                        ok = false;
                    }
                }
            }
            if (last != last2 - 1)ok = false;
            if (!ok) {
                if (last != -inf)cnt[last]++;
                if (last2 != -inf)cnt[last2]++;
                cnt[0] += c;cnt[9] += c;
                continue;
            }
            int res = 0;
            for (int i = 1;i < 10;++i) {
                int x = cnt[i];
                x /= 2;
                if (x && ok) {
                    res = i;
                    x--;
                    for (int j = 0;j < cnt[0];++j)res = res * 10;
                    ok = false;
                }
                for (int j = 0;j < x;++j)res = res * 10 + i;
            }
            res = res * 10 + last;
            // std::cout << res << ' ';
            // if (cnt[0] + c == 0 && cnt[1] == 1 && cnt[2] == 1 && pos == 3) {
            //     std::cout << res << ' ' << c << ' ';
            // }
            if (ok && cnt[0]) {
                if (last != -inf)cnt[last]++;
                if (last2 != -inf)cnt[last2]++;
                cnt[0] += c;cnt[9] += c;
                continue;
            }
            for (int j = 0;j < c;++j)res = res * 10 + 9;
            min = std::min(min, res);

            if (last != -inf)cnt[last]++;
            if (last2 != -inf)cnt[last2]++;
            cnt[0] += c;cnt[9] += c;
        }
        if (min != inf) {
            // if (min == 1) {
            //     for (int x : cnt)std::cout << x << ' ';std::cout << '\n';
            //     std::cout << pos << '\n';
            // }
            // std::cout << min << ' ';std::cout << '\n';
            map[min]++;
        }
        return min;
        };
    // cnt[1] = 1, cnt[2] = 1;
    // cal(3);
    auto dfs = [&](this auto&& dfs, int pos, int sum)->void {
        if (sum >= 10 || pos >= 10)return;
        // if (pos == 3 && cnt[0] == 0 && cnt[1] == 1 && cnt[2] == 1)std::cout << "aaa" << '\n';
        for (int i = 0;i < 10;++i) {
            cnt[pos] = i;
            if (i && sum + i < 10)cal(pos + 1);
            dfs(pos + 1, sum + i);
        }
        cnt[pos] = 0;
        };
    dfs(0, 0);
    int count = 0;
    for (auto& [x, y] : map) {
        std::cout << x << " " << y << '\n';
        // assert(y == 1);
        y = ++count;
    }
    // int t;std::cin >> t;
    // while (t--) {
    //     solve();
    //     std::cout << '\n';
    // }
    return 0;
}