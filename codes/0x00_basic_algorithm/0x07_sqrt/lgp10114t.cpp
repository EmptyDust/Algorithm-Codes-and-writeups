#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 2e6 + 10;
ll n;
ll d[MAXN], di = 0;
unordered_map<ll, int> mp;

ll cal(ll x) {
    ll cnt = 0;
    while (x) {
        x -= x & -x;
        cnt++;
    }
    return cnt;
}
//x&-x lowbit
//1011100 100

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    ll tmp;
    for (int i = 0;i < n;++i) {
        cin >> tmp;
        mp[tmp]++; //key:value
        if (mp[tmp] == 1)d[di++] = tmp;
    }
    ll sum = 0;
    for (int i = 0;i < di;++i)
        for (int j = 0;j < di;++j)
            sum += 1LL * mp[d[i]] * mp[d[j]] * (cal(d[i] + d[j]) + cal(abs(d[i] - d[j])));
    cout << sum;
    return 0;
}