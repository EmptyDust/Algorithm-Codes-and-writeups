//
//   ____      _                           _          _    __     ____     ___    ____    _____ 
//  |  _ \    (_)   __ _   _ __     __ _  | |   ___  / |  / /_   |___ \   ( _ )  | ___|  |___  |
//  | | | |   | |  / _` | | '_ \   / _` | | |  / _ \ | | | '_ \    __) |  / _ \  |___ \     / / 
//  | |_| |   | | | (_| | | | | | | (_| | | | |  __/ | | | (_) |  / __/  | (_) |  ___) |   / /  
//  |____/   _/ |  \__,_| |_| |_|  \__, | |_|  \___| |_|  \___/  |_____|  \___/  |____/   /_/   
//          |__/                   |___/                                                        
//
//  [题目链接] ： 
//
//  [题目名称] ： 
//
//  [  做法  ] ： 
//
#include <bits/stdc++.h>
#define fir first
#define sec second
#define el '\n'
#define all(x) (x).begin(), (x).end()
#define FINISH cout << "FINISH" << endl;
#define debug(x) cout << #x << " :== " << x << endl;
#define debugv(x)\
    cout << #x << " :: ";\
    for (auto v : x) cout << v << " ";\
    cout << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int mod = 998244353;
const int inf32 = 0x3f3f3f3f;
const ll inf64 = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "  " + s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 2; i < n; i++) {
        if (s[i] == '0')
            cnt0++;
    }

    if (cnt0 == 0) {
        cout << "-1" << el;
        return;
    }
    if (cnt0 == 1) {
        if (s[n - 1] == '0') {
            cout << n - 1 << el;
            for (int i = 2; i < n; i++) {
                cout << i - 1 << " " << i << endl;
            }
            cout << 1 << " " << n << endl;
        }
        else {
            cout << "-1" << el;
        }
        return;
    }

    vector<PII> ans;
    int las0 = 1, las1 = 1;
    for (int i = 2; i < n; i++) {
        if (s[i] == '0') {
            ans.push_back({ i, las0 });
            las0 = i;
        }
        else {
            ans.push_back({ i, las1 });
            las1 = i;
        }
    }
    ans.push_back({ las0, 1 });
    ans.push_back({ las1, n });

    cout << ans.size() << el;
    for (auto [x, y] : ans) {
        cout << x << " " << y << el;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}