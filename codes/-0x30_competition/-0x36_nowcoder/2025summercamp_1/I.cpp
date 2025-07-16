//
//   ____      _                           _          _    __     ____     ___    ____    _____ 
//  |  _ \    (_)   __ _   _ __     __ _  | |   ___  / |  / /_   |___ \   ( _ )  | ___|  |___  |
//  | | | |   | |  / _` | | '_ \   / _` | | |  / _ \ | | | '_ \    __) |  / _ \  |___ \     / / 
//  | |_| |   | | | (_| | | | | | | (_| | | | |  __/ | | | (_) |  / __/  | (_) |  ___) |   / /  
//  |____/   _/ |  \__,_| |_| |_|  \__, | |_|  \___| |_|  \___/  |_____|  \___/  |____/   /_/   
//          |__/                   |___/                                                        
//
//  [题目链接] ： 
//
//  [题目名称] ： 
//
//  [  做法  ] ： 
//
#include <bits/stdc++.h>
#define fir first
#define sec second
#define el '\n'
#define all(x) (x).begin(), (x).end()
#define FINISH cout << "FINISH" << endl;
#define debug(x) cout << #x << " :== " << x << endl;
#define debugv(x)\
    cout << #x << " :: ";\
    for (auto v : x) cout << v << " ";\
    cout << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int mod = 998244353;
const int inf32 = 0x3f3f3f3f;
const ll inf64 = 0x3f3f3f3f3f3f3f3f;

ll clog2(ll x)
{
    int k = 63 - __builtin_clzll(x);
    if (1ll << k == x)
        return k;
    return k + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<ll> sum(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    vector dp(n + 1, vector<vector<array<ll, 2>>>(n + 1));

    auto get = [&](int l, int r, ll B) ->ll {
        if (l == r) return 0;
        auto it = ranges::upper_bound(dp[l][r], array<ll, 2>{ B, inf64 });
        if (it == dp[l][r].begin()) return -1;
        --it;
        return (*it)[1];
        };

    for (int len = 1;len < n - 1;++len) {
        for (int l = 1;l <= n - len;++l) {
            int r = l + len;

            std::vector<std::array<ll, 2>> temp;
            ll w = clog2(sum[r] - sum[l - 1]);

            for (int g = l; g < r; g++) {
                ll L = sum[g] - sum[l - 1];
                ll R = sum[r] - sum[g];
                ll nowB = abs(R - L);

                ll lval = get(l, g, nowB);
                ll rval = get(g + 1, r, nowB);
                ll now = min(L, R) * w;
                if (lval == -1 || rval == -1)
                    continue;

                ll nowans = lval + rval + now;
                temp.push_back({ nowB, nowans });
            }

            ranges::sort(temp);
            for (int j = 0;j < temp.size();++j)
                if (dp[l][r].empty() || dp[l][r].back()[1] > temp[j][1])
                    dp[l][r].push_back({ temp[j][0], temp[j][1] });
        }
    }
    // ranges::sort(vt);
    // for (auto [x, y] : vt)std::cout << x << ' ' << y << '\n';

    ll w = clog2(sum[n]);
    for (int i = 1; i < n; i++) {
        ll L = sum[i];
        ll R = sum[n] - sum[i];
        ll nowB = abs(R - L);

        ll lval = get(1, i, nowB);
        ll rval = get(i + 1, n, nowB);
        ll now = min(L, R) * w;

        if (lval == -1 || rval == -1)
            cout << "-1 ";
        else
            cout << lval + rval + now << " ";
    }
    cout << el;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
