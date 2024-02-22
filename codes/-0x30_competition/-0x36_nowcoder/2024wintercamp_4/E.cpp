#include <bits/stdc++.h>
#define int long long 
#define op first
#define num second
using namespace std;
constexpr int MAXN = 2e5 + 10, mod = 1e9 + 7;
int nums[MAXN], sums[MAXN], f[MAXN];
using pt = pair<int, int>;
int n, k;

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    map<int, int> mp;
    mp[0] = 0;
    for (int i = 1;i <= n;++i) {
        cin >> nums[i];
        sums[i] = (sums[i - 1] + nums[i]) % k;
        if (mp.count(sums[i]))f[i] = max(f[i - 1], f[mp[sums[i]]] + 1);
        else f[i] = f[i - 1];
        mp[sums[i]] = i;
    }
    //for (int i = 1;i <= n;++i)cout << f[i] << ' ';
    cout << f[n];
    return 0;
}