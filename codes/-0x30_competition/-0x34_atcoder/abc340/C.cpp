#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
map<int, int> mp;
using pt = pair<int, int>;

int f(int x) {
    if (x == 1)return 0;
    if (mp.count(x))return mp[x];
    return mp[x] = x + f(x / 2) + f(x / 2 + (x % 2));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int x;cin >> x;
    cout << f(x);
    return 0;
}