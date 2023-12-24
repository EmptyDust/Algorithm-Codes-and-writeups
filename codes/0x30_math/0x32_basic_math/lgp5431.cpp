#include <bits/stdc++.h>
//#define int long long 
#define ll long long
using namespace std;
constexpr int MAXN = 5e6 + 10;
int nums[MAXN], ks[MAXN], pre[MAXN], suf[MAXN];

char buf[(int)1e8], * ss = buf;
inline int init() { buf[fread(buf, 1, (int)1e8 - 1, stdin)] = '\n';fclose(stdin);return 0; }
const int __START__ = init();

inline int readint() {
    int d = 0;
    while (!isdigit(*ss))++ss;
    while (isdigit(*ss))d = d * 10 + (*ss++ ^ '0');
    return d;
}

void exGCD(int a, int b, int& x, int& y) {
    if (!b)x = 1, y = 0;
    else exGCD(b, a % b, y, x), y -= a / b * x;
}

int inv(int a, int b) {
    int x, y;
    exGCD(a, b, x, y);
    x = (x % b + b) % b;
    return x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, p, k;
    n = readint(), p = readint(), k = readint();
    ks[0] = 1;
    for (int i = 1;i <= n;++i)ks[i] = ((ll)ks[i - 1] * k) % p;
    for (int i = 1;i <= n;++i)nums[i] = readint() % p;
    pre[0] = 1, suf[n + 1] = 1;
    for (int i = 1;i <= n;++i)pre[i] = ((ll)pre[i - 1] * nums[i]) % p;
    for (int i = n;i >= 1;--i)suf[i] = ((ll)suf[i + 1] * nums[i]) % p;
    ll ans = 0;
    for (int i = 1;i <= n;++i)ans = (ans + (((ll)ks[i] * pre[i - 1]) % p * suf[i + 1]) % p) % p;
    ans = (ans * inv(pre[n], p)) % p;
    cout << ans;
    return 0;
}