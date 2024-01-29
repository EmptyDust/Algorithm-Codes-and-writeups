#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e9 + 7;
constexpr int MAXN = 2e5;
vector<int> pts[MAXN];
string s;

int qpow(int a, int n) {
    int ans = 1;
    while (n) { if (n & 1)ans = ans * a % mod;a = a * a % mod;n >>= 1; }
    return ans;
}

#define inv(x) qpow(x,mod-2)

int c(int a, int b) {
    if (a < b)return 0;
    if (b > a / 2)b = a - b;
    int ans = 1;
    for (int i = a, j = 1;j <= b;--i, ++j)
        ans = ans * i % mod * inv(j) % mod;
    return ans % mod;
}

signed main() {
    int m, n;cin >> m >> n;
    cout << c(m, n);
}