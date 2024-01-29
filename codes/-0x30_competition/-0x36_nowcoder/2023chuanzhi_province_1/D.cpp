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

int cntt = 0;

int get_num(int x) {
    cntt++;
    if (pts[x].empty())return 1;
    int ret = 1;
    for (auto p : pts[x]) if (s[p] != 'R') {
        ret += get_num(p);
    }
    return ret;
}

int ans = 1;

void red_t(int x) {
    int num = get_num(x);
    int ret = 0;
    for (int k = (3 - num % 3) % 3;k <= num;k += 3)
        ret = (ret + c(num, k)) % mod;
    ans = ans * ret % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    int n, tmp;
    cin >> n >> s;
    for (int i = 1;i < n;++i) {
        cin >> tmp;
        pts[tmp - 1].push_back(i);
    }
    vector<int> red_;
    for (int i = 0;i < n;++i)if (s[i] == 'R')
        red_.push_back(i);
    for (int num : red_)
        red_t(num);
    ans = ans * qpow(2, n - cntt) % mod;
    cout << ans;

    return 0;
}