#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 1e6 + 10;
const int N = 1e6;

using a2 = std::array<int, 2>;

std::vector<int> next, prime;

void init()
{
    next.assign(MAXN, 1);
    for (int i = 2; i < N; ++i)
    {
        if (next[i] == 1)
        {
            prime.push_back(i);
        }
        for (auto x : prime)
        {
            if (1ll * x * i > N)
                break;
            next[x * i] = i;
        }
    }
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n), f(MAXN);
    for (auto &x : a)
    {
        std::cin >> x;
        f[x]++;
    }
    std::sort(a.begin(), a.end());
    std::vector<int> ans1(n + 1), ans2(n + 1), ans3(n + 1);
    int mex = 0;
    bool ch = 0;
    for (int x : a)
    {
        if (x < mex)
            ch = 1;
        if (x == mex)
        {
            mex++;
            if (mex == 1)
                ans1[mex] = 1;
            else if (mex % 2 == 0 || !ch)
                ans1[mex] = mex ^ 1;
            else
                ans1[mex] = mex;
        }
    }
    for (int i = mex + 1; i <= n; ++i)
    {
        if (mex % 2 == 0 || !ch)
            ans1[i] = mex ^ 1;
        else
            ans1[i] = ans1[mex];
    }
    int cnt = std::count(a.begin(), a.end(), 0);
    for (int i = N; i >= 2; --i)
    {
        if (f[i] == 0)
            continue;
        ans2[f[i]] = std::max(ans2[f[i]], i);
        ans3[f[i]] = std::max(ans3[f[i]], i ^ 1);
        f[next[i]] += f[i];
    }
    std::deque<a2> q;
    for (int i = 1; i <= n; ++i)
    {
        while (q.size() && q.front()[1] < i)
            q.pop_front();
        while (q.size() && q.back()[0] <= ans3[i])
            q.pop_back();
        auto tmp = ans3[i];
        if (q.size())
            ans3[i] = q.front()[0];
        else
            ans3[i] = 0;
        q.push_back({tmp, i + cnt});
    }
    for (int i = n - 1; i >= 1; --i)
        ans2[i] = std::max(ans2[i], ans2[i + 1]);
    // for (int x : ans1)
    //     std::cout << x << ' ';
    // std::cout << '\n';
    // for (int x : ans2)
    //     std::cout << x << ' ';
    // std::cout << '\n';
    // for (int x : ans3)
    //     std::cout << x << ' ';
    // std::cout << '\n';
    for (int i = 1; i <= n; ++i)
    {
        std::cout << std::max({ans1[i], ans2[i], ans3[i]}) << ' ';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int t = 1;
    while (t--)
        solve();
    return 0;
}