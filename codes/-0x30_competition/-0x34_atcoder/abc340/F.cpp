#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
using pt = pair<int, int>;

void exGCD(int a, int b, int& x, int& y) {
    if (!b) x = 1, y = 0;
    else exGCD(b, a % b, y, x), y -= a / b * x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int x, y;cin >> x >> y;
    int a, b;exGCD(x, y, b, a);
    int gcd = abs(__gcd(x, y));
    if (gcd == 1)
        cout << -a * 2 << ' ' << b * 2;
    else if (gcd == 2)
        cout << -a << ' ' << b;
    else
        cout << -1;
    return 0;
}