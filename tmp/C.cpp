
#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    bool f=1;
    cin >> s;
    int zhi=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='H'){
            zhi+=s.size()-i;
        }
    }
    if(zhi%2==0)f=0;
    cout<<(f?"Alice":"Bob");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    // int t;std::cin >> t;
    // while (t--) {
        solve();
        // std::cout << '\n';
    // }
    return 0;
}