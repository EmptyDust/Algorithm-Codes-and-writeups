#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

#define lowbit(x) x&-x
int BIT[MAXN];
int n, q;
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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> q;
    std::vector<int> b(n, -1), a(n);
    for (int& x : a)std::cin >> x;
    std::stack<int> stk;
    for (int i = 0;i < n;++i) {
        while (stk.size() && a[stk.top()] > a[i]) {
            b[stk.top()] = i + 1;
            update(i + 1);
            stk.pop();
        }
        stk.push(i);
    }
    std::vector<a3> a3s(q);int idx = 0;
    std::vector<int> ans(q);
    for (auto& [l, r, i] : a3s)std::cin >> l >> r, i = idx++;
    std::sort(a3s.begin(), a3s.end());
    int cur = 0;
    for (auto& [l, r, i] : a3s) {
        while (cur < l - 1) {
            if (b[cur] != -1)
                update(b[cur], -1);
            cur++;
        }
        ans[i] = query(r);
    }
    for (int& x : ans)std::cout << x << '\n';
    return 0;
}