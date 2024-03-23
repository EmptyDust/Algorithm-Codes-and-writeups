#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

std::vector<int> a{ 'a','4','b','6','c','c','d','d','e','3','f','f','g','9','h','h','i','i','j','j','k','k','l','1','m','m','n','n','o','0','p','p','q','q','r','r','s','5','t','7','u','u','v','v','w','w','x','x','y','y','z','2' };


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::map<char, char> mp;
    for (int i = 0;i < a.size();i += 2) {
        mp[a[i + 1]] = a[i];
    }
    std::string s, t;
    std::getline(std::cin, s);
    for (char c : s) {
        if (mp.count(c))
            t += mp[c];
        else
            t += c;
    }
    std::cout << t;
    return 0;
}