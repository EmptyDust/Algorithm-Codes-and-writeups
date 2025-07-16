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

    vector dp(n + 1, vector<map<ll, ll, std::greater<ll>>>(n + 1));
    vector vis(n + 1, std::vector(n + 1, false));

    auto dfs = [&](auto& self, int l, int r, ll B) -> ll
        {
            if (l == r)
                return 0;

            if (!vis[l][r]) {
                vis[l][r] = 1;
                std::vector<std::array<ll, 2>> temp;
                ll w = clog2(sum[r] - sum[l - 1]);
                for (int i = l; i < r; i++) {
                    ll L = sum[i] - sum[l - 1];
                    ll R = sum[r] - sum[i];
                    ll nowB = abs(R - L);

                    ll lval = self(self, l, i, nowB);
                    ll rval = self(self, i + 1, r, nowB);
                    ll now = min(L, R) * w;
                    if (lval == -1 || rval == -1)
                        continue;

                    ll nowans = lval + rval + now;
                    temp.push_back({ nowB, nowans });
                }
                if (temp.size()) {
                    ranges::sort(temp);
                    dp[l][r][temp[0][0]] = temp[0][1];
                    for (int j = 1;j < temp.size();++j) {
                        if (temp[j - 1][1] > temp[j][1]) {
                            dp[l][r][temp[j][0]] = temp[j][1];
                        }
                        else temp[j][1] = temp[j - 1][1];
                    }
                }
            }

            auto it = dp[l][r].lower_bound(B);
            if (it == dp[l][r].end()) return -1;
            return (*it).second;
        };

    for (int i = 1; i < n; i++) {
        ll L = sum[i];
        ll R = sum[n] - sum[i];
        ll nowB = abs(R - L);

        ll lval = dfs(dfs, 1, i, nowB);
        ll rval = dfs(dfs, i + 1, n, nowB);
        ll now = 1ll * min(L, R) * clog2(L + R);

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
    // std::cout << clog2(1) << '\n';
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
