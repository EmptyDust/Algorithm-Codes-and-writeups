#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, q;std::cin >> n >> q;

    std::vector<int> l(q), r(q);
    for (int& x : l)std::cin >> x;
    for (int& x : r)std::cin >> x;

    std::deque<int> dq[n + 1];
    for (int i = 1;i <= n;++i)dq[i].push_back(i);
    for (int i = q - 1;i >= 0;--i) {
        if (l[i] > r[i])dq[l[i]].push_back(r[i]);
        else dq[r[i]].push_front(l[i]);
    }
    int first = std::max(l[0], r[0]);

    std::vector<int> vt;
    std::function<void(int)> func = [&](int x) ->void {
        for (int y : dq[x]) {
            if (x == y)vt.push_back(y);
            else func(y);
        }
        };
    func(first);

    int m = vt.size();
    std::vector<int> zbs(m);
    std::iota(zbs.begin(), zbs.end(), 0);
    std::sort(zbs.begin(), zbs.end(), [&](int a, int b) {
        return vt[a] > vt[b];
        });
    std::vector<bool> used(m + 1, true);
    int cnt = 0, cur = n;
    i64 ans = 1;
    for (int pos : zbs) {
        int num = vt[pos];
        while (cur > num) {
            ans = ans * cnt % mod;
            cnt++;
            cur--;
        }
        cnt += used[pos] + used[pos + 1];
        used[pos] = used[pos + 1] = 0;
        cur--;
    }
    while (cur > 0) {
        ans = ans * cnt % mod;
        cnt++;
        cur--;
    }
    std::cout << ans;
    return 0;
}
