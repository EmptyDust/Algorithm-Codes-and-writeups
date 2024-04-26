#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], f[MAXN], poss[MAXN], vis[MAXN], n, k;
using pt = std::pair<int, int>;
/*
For two permutations p
 and q
 of the same size n
, the permutation w=q⋅p
 is such that wi=pqi
 for all 1≤i≤n
.
*/
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

void solve() {
    std::cin >> n >> k;
    for (int i = 1;i <= n;++i) {
        vis[i] = 0;//init
        BIT[i] = 0;
    }
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    int rev = 0;
    for (int i = 1;i <= n;++i) {
        f[i] = query(nums[i]);
        rev += i - 1 - f[i];
        update(nums[i]);
    }
    if (rev > k || (k - rev) % 2 == 1) {
        std::cout << "NO";
        return;
    }
    k -= rev;
    k /= 2;
    std::iota(poss, poss + n + 1, 0);
    std::sort(poss + 1, poss + n + 1, [&](int a, int b) {return nums[a] > nums[b];});
    std::vector<int> ans;
    int x = n, y = -1;
    for (int i = 1;i <= n;++i) {
        int cur = poss[i];
        if (f[cur] <= k) {
            k -= f[cur];
            ans.push_back(cur);
            vis[cur] = 1;
        }
        else {
            vis[cur] = 1;
            for (x = y = cur;x && k;--x)if (nums[i] < nums[cur])
                k--;
            break;
        }
    }
    if (k) {
        std::cout << "NO";
        return;
    }
    for (int i = 1;i <= x;++i)if (!vis[i])
        ans.push_back(i);
    if (~y) {
        ans.push_back(y);
        for (int i = x + 1;i <= n;++i)if (!vis[i])
            ans.push_back(i);
    }
    std::cout << "YES" << '\n';
    for (int num : ans)std::cout << num << ' ';
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