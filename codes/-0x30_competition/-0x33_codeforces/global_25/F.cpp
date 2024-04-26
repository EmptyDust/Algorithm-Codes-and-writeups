#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 n, k;
int q[MAXN], p[MAXN], qp[MAXN], cnt[MAXN];
using pt = std::pair<int, int>;

#define lowbit(x) x&-x
int BIT[MAXN];
void update(int pos, int num = 1) {
    for (int i = pos;i <= n;i += lowbit(i))
        BIT[i] += num;
}
int query(int pos) {
    int ret = 0;
    for (int i = pos;i;i -= lowbit(i))
        ret += BIT[i];
    return ret;
}

i64 cal(int nums[MAXN]) {
    for (int i = 1;i <= n;++i)
        BIT[i] = 0;
    i64 rev = 0;
    for (int i = 1;i <= n;++i) {
        cnt[i] = query(nums[i]);
        rev += i - 1 - cnt[i];
        update(nums[i]);
    }
    return rev;
}

void solve() {
    std::cin >> n >> k;
    for (int i = 1;i <= n;++i)qp[i] = 1;
    for (int i = 1;i <= n;++i)std::cin >> p[i];
    i64 rev = cal(p);
    if (k < rev || k > n * (n - 1) - rev || (k - rev) % 2 == 1) {
        std::cout << "NO";
        return;
    }
    std::cout << "YES" << '\n';
    k = (k - rev) / 2;
    for (int i = 1;i <= n;++i) {
        if (cnt[i] < k) {
            k -= cnt[i];
        }
        else {
            for (int j = 1, v = i; j < i; j++) {
                qp[j] = v--;
                if (p[j] < p[i] && --k == 0) {
                    qp[i] = v--;
                }
            }
            for (int j = i + 1; j <= n; j++) {
                qp[j] = j;
            }
            break;
        }
    }
    for (int i = 1;i <= n;++i)
        q[p[i]] = qp[i];
    for (int i = 1;i <= n;++i)
        std::cout << q[i] << ' ';
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