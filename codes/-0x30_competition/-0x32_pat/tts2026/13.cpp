#include <bits/stdc++.h>

#define ranges std::ranges

using i64 = long long;
using info1 = std::array<int, 4>;
const int mod = 998244353;
const int inf = 2e9;

void solve(){
    int n; std::cin>>n;
    std::vector<info1> info(n);
    for(auto& [dd, yy, id, age]:info) std::cin>>dd>> yy>>id>>age; 
    
    std::set<int> wait, old;
    std::vector<int> curtime(20001, -1);

    auto push = [&](info1 info, int p){
        auto [dd, yy, id, age] = info;
        if(age >= 80) old.insert(id);
        wait.insert(id);
        curtime[yy] = id;
    };

    int cnt = 0;
    auto output = [&](int id, int time){
        cnt++;
        std::string s = std::to_string(id);
        while(s.length() < 5) s = "0" + s;
        std::cout<<time<<' '<<s<<'\n';
    };

    int i = 0;
    for(int t = 1, i = 0; cnt != n; ++t){
        while(i < n && info[i][0] == t){
            push(info[i], i);
            i++;
        }
        // std::cerr<<t<<' '<<wait.size()<<'\n';
        if(curtime[t] != -1 && wait.contains(curtime[t])){
            int x = curtime[t];
            output(x, t);
            old.erase(x);
            wait.erase(x);
        }
        else if(old.size()){
            int x = *old.begin();
            output(x, t);
            old.erase(x);
            wait.erase(x);
        }
        else if(wait.size()){
            int x = *wait.begin();
            output(x, t);
            wait.erase(x);
        }
    }
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

/*
9
1 3 00000 28
1 1 37428 79
2 8 81926 83
2 2 37610 80
3 7 46381 13
6 6 73846 93
8 5 18264 37
8 9 57382 24
8 4 27364 88


*/