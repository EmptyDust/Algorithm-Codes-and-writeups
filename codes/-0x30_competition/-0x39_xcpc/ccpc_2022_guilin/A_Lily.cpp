#include<bits/stdc++.h>

void solve(){
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    for (int i = 0;i < n;++i){
        if (s[i] == '.')
            if ((!i || s[i - 1] != 'L') && (i == n - 1 || s[i + 1] != 'L'))
                s[i] = 'C';
    }
    std::cout << s;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--){
        solve();
        std::cout << '\n';
    }
    return 0;
}