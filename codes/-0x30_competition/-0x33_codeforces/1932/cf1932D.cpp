#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    char suit;cin >> suit;
    vector<int> suits;
    string s;
    map<char, int> mp;
    int cnt = 0;
    vector<string> ans;
    for (int i = 0;i < 2 * n;++i) {
        cin >> s;
        int num = s[0] - '0';
        if (s[1] == suit)suits.push_back(num);
        else {
            if (!mp[s[1]])mp[s[1]] = num, cnt++;
            else {
                int tmp = mp[s[1]];
                if (tmp > num)swap(tmp, num);
                string anst = "";
                anst += (char)(tmp + '0');
                anst += s[1];
                anst += ' ';
                anst += (char)(num + '0');
                anst += s[1];
                ans.push_back(anst);
                mp[s[1]] = 0;
                cnt--;
            }
        }
    }
    sort(suits.begin(), suits.end());
    int t = 0;
    for (auto [ch, num] : mp)if (num && t < suits.size()) {
        string anst = "";
        anst += (char)(num + '0');
        anst += ch;
        anst += ' ';
        anst += (char)(suits[t] + '0');
        anst += suit;
        ans.push_back(anst);
        t++;
        cnt--;
    }
    if ((suits.size() - t) % 2 == 0)for (;t < suits.size();t += 2) {
        string anst = "";
        anst += (char)(suits[t] + '0');
        anst += suit;
        anst += ' ';
        anst += (char)(suits[t + 1] + '0');
        anst += suit;
        ans.push_back(anst);
    }
    else cnt = 1;
    if (!cnt) {
        for (auto str : ans)cout << str << '\n';
    }
    else cout << "IMPOSSIBLE" << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}