#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int m = 1000001;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int>x(n + 1), y(n + 1), pre(n + 1), nxt(n + 1);
    vector<unordered_map<int, int>>bit(m + 1);
    auto lowbit = [&](int x)->int
        {return x & -x;};
    auto add1 = [&](int x, int y, int v)->void
        {
            for (int i = x;i;i -= lowbit(i))
            {
                for (int j = y;j;j -= lowbit(j))
                {
                    if (!bit[i].count(j))bit[i][j] = 0;
                    bit[i][j] = max(bit[i][j], v);
                }
            }
        };
    auto add2 = [&](int x, int y, int v)->void
        {
            for (int i = x;i;i -= lowbit(i))
            {
                for (int j = y;j;j -= lowbit(j))
                {
                    if (!bit[i].count(j))bit[i][j] = n + 1;
                    bit[i][j] = min(bit[i][j], v);
                }
            }
        };
    auto ask1 = [&](int x, int y)->int
        {
            int ans = 0;
            for (int i = x;i <= m;i += lowbit(i))
            {
                for (int j = y;j <= m;j += lowbit(j))
                {
                    if (bit[i].count(j))ans = max(ans, bit[i][j]);
                }
            }
            return ans;
        };
    auto ask2 = [&](int x, int y)->int
        {
            int ans = n + 1;
            for (int i = x;i <= m;i += lowbit(i))
            {
                for (int j = y;j <= m;j += lowbit(j))
                {
                    if (bit[i].count(j))ans = min(ans, bit[i][j]);
                }
            }
            return ans;
        };
    for (int i = 1;i <= n;i++)
    {
        cin >> x[i];
        x[i]++;
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> y[i];
        y[i]++;
    }
    for (int i = 1;i <= n;i++)
    {
        pre[i] = ask1(x[i], y[i]);
        add1(x[i], y[i], i);
    }
    for (int i = 1;i <= m;i++)bit[i].clear();
    for (int i = n;i >= 1;i--)
    {
        nxt[i] = ask2(x[i], y[i]);
        add2(x[i], y[i], i);
    }
    for (int i = 1;i <= m;i++)bit[i].clear();
    vector<unordered_map<int, int>>().swap(bit);
    vector<int>ans(q + 1);
    vector<vector<array<int, 2>>>que(n + 1);
    for (int i = 1;i <= q;i++)
    {
        int l, r;
        cin >> l >> r;
        que[l].push_back({ r,i });
    }
    vector<vector<array<int, 2>>>upd(n + 1);
    for (int i = 1;i <= n;i++)
    {
        upd[pre[i] + 1].push_back({ nxt[i] - 1,i });
    }
    bit.resize(n + 1);
    auto add = [&](int x, int y, int v)->void
        {
            for (int i = x;i;i -= lowbit(i))
            {
                for (int j = y;j;j -= lowbit(j))
                {
                    bit[i][j] += v;
                }
            }
        };
    auto ask = [&](int x, int y)->int
        {
            int ans = 0;
            for (int i = x;i <= n;i += lowbit(i))
            {
                for (int j = y;j <= n;j += lowbit(j))
                {
                    ans += bit[i][j];
                }
            }
            return ans;
        };
    for (int i = 1;i <= n;i++)
    {
        for (auto [r, id] : upd[i])
        {
            add(r, id, 1);
        }
        for (auto [r, id] : que[i])
        {
            ans[id] = ask(r, i) - ask(r, r + 1);
        }
    }
    for (int i = 1;i <= q;i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}