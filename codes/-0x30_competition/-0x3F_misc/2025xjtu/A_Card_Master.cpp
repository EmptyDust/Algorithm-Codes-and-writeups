
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,c;  std::cin >> a >> b >> c;
    int sum = a + b + c;
    std::cout << (a == b && b == c ? sum + 100 : sum);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    // int t;std::cin >> t;
    // while (t--) {
        solve();
        std::cout << '\n';
    // }
    return 0;
}