#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    n--;
    int a = 1, b = 1, c = 1;

    while (n--) {
        if (c < b) {
            c = c * 10 + 1;
        }
        else if (b < a) {
            b = b * 10 + 1;
            c = 1;
        }
        else {
            a = a * 10 + 1;
            b = c = 1;
        }
    }
    cout << a + b + c;
    return 0;
}