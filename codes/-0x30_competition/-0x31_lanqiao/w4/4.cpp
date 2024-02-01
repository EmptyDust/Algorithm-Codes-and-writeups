#include <bits/stdc++.h>
#define int long long
#define l first
#define r second
using namespace std;
using pt = pair<int, int>;
constexpr int MAXN = 1e5 + 10;
int nums[MAXN], n, q;
pt qys[MAXN];

struct cmp {
    bool operator()(int a, int b) {
        return qys[a].r < qys[b].r;
    }
};

signed main()
{
    // 请在此输入您的代码
    cin >> n >> q;
    vector<int> zbs(n), zbq(q), higher(n, INT_MAX);
    vector<bool> ans(q, false);
    for (int i = 0;i < n;++i)cin >> nums[i];
    for (int i = 0;i < q;++i)cin >> qys[i].l >> qys[i].r, qys[i].l--, qys[i].r--;
    iota(zbs.begin(), zbs.end(), 0);
    iota(zbq.begin(), zbq.end(), 0);
    sort(zbs.begin(), zbs.end(), [&](int a, int b) {return nums[a] < nums[b];});
    sort(zbq.begin(), zbq.end(), [&](int a, int b) {return qys[a].l < qys[b].l;});
    for (int i = 0, k;i < n;++i) {
        for (int k = i + 1;k < n && nums[zbs[k]] - nums[zbs[i]] <= 365;++k) {
            int m = min(zbs[k], zbs[i]);
            higher[m] = min(higher[m], abs(zbs[k] - zbs[i]));
        }
    }
    deque<int> que;
    for (int i = 0, t = 0;i < n;++i) {
        while (t < q && qys[zbq[t]].l <= i)que.push_back(zbq[t++]);
        while (!que.empty() && qys[que.back()].r >= i + higher[i]) {

        }
    }
    for (auto f : ans)cout << (f ? "YES" : "NO") << '\n';

    return 0;
}