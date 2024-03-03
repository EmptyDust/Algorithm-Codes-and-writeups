#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

bool solve() {
    int x, y, z;cin >> x >> y >> z;
    if (x + y * 2 + z * 3 != 7 * 7 * 7 * 3)return false;
    //z = a*b*c
    int ab_ac_bc = y + 3 * z;
    if (ab_ac_bc % 7)return false;
    ab_ac_bc /= 7;
    for (int a = 1;a <= 7;++a)
        for (int b = 1;b <= 7;++b)
            for (int c = 1;c <= 7;++c) {
                if (a * b * c == z && a * b + b * c + a * c == ab_ac_bc) {
                    cout << "Yes" << '\n';
                    cout << a << ' ' << 0 << ' ' << c << ' ';
                    cout << a - 7 << ' ' << b - 7 << ' ' << 0 << ' ';
                    cout << -7 << ' ' << b << ' ' << c << ' ';

                    return true;
                }
            }

}

signed main() {
    ios::sync_with_stdio(false);
    if (!solve())cout << "No";
    return 0;
}