#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e9 + 7;
constexpr int MAXN = 2e5;
vector<int> pts[MAXN];
string s;

int zh(int a, int b) {
    if (a < b)return 0;
    if (b > a / 2)b = a - b;
    int tmp = b;
    int ans = 1;
    for (int i = a;i > a - b;--i) {
        int t = i;
        while (tmp > 1 && t % tmp == 0) { t /= tmp;tmp--; }
        ans = (ans * t) % mod;
    }
    return ans % mod;
}

int pow2(int n) {
    if (n == 0)return 1;
    if (n == 1)return 2;
    int tmp = (pow2(n / 2) * pow2(n / 2)) % mod;
    if (n & 1)return (tmp * 2) % mod;
    return tmp % mod;
}

int cntt = 0;

int get_num(int x) {
    cntt++;
    if (pts[x].empty())return 1;
    int ret = 0;
    for (auto p : pts[x]) if (s[p] != 'R') {
        ret += get_num(p);
    }
    return ret + 1;
}

int ans = 1;

void red_t(int x) {
    int num = get_num(x);
    int ret = 0;
    for (int k = (3 - num % 3) % 3;k <= num;k += 3) {
        //cout << zh(num, k) << endl;
        ret = (ret + zh(num, k)) % mod;
    }
    ans = (ans * ret) % mod;
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
    ans = (ans * pow2(n - cntt)) % mod;
    cout << ans % mod;

    return 0;
}