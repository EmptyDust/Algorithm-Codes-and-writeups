#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, k;cin >> n >> m >> k;
    int gcd = __gcd(n, m);
    int mul = n * m / gcd;
    int cnt = m / gcd + n / gcd - 2;
    int ans = k / cnt * mul;
    k %= cnt;
    if (!k)k += cnt, ans -= mul;
    auto check = [&](int x)->bool {
        return x / n + x / m - x / mul >= k;
        };
    int l = 1, r = mul, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    l = max(l / n * n, l / m * m);
    //cout << ans << endl;
    cout << ans + l;
    return 0;
}