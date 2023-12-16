#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    cout << (min(abs(s1[1] - s1[0]), 5 - abs(s1[1] - s1[0])) == min(5 - abs(s2[1] - s2[0]), abs(s2[1] - s2[0])) ? "Yes" : "No");
    return 0;
}