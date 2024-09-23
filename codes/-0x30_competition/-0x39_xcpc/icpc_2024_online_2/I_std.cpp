#include<bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;

int arr[32];
bool dfs(int i, bool f, i64 n) // f 为true选了0
{
    if(i == 32){
        i64 ans = 0;
        for(int i = 0; i < 32; i++){
            ans += (1LL << i) * arr[i];
        }
        return n == ans;
    }
    bool flag = false;
    if(f){
        arr[i] = 1;
        flag |= dfs(i + 1, true, n);
        arr[i] = -1;
        
    }
}

void solve() {
    i64 n;std::cin >> n;
    i64 y = n % 4;
    if (y == 0) {
        std::cout << "NO";
        return;
    }else if(y == 1){
        std::cout << "mod = 1\n";
    }else if(y == 2){
        std::cout << "mod = 2\n";

    }else{
        std::cout << "mod = 3\n";
    }  
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}