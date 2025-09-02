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
    int n, m;
    cin >> n >> m;
    vector<PII> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i].fir >> a[i].sec;
    }
    sort(next(a.begin()), a.end(), [](PII x, PII y) {
        if (x.fir == y.fir)
            return x.sec > y.sec;
        return x.fir > y.fir;
        });
    vector<int> ans(n * 2 + 1, 0);
    int tot = 0, las = n * 2 + 1;
    for (int i = 1; i <= m; i++) {
        //         cout << a[i].fir << " " << a[i].sec << endl;
        if (a[i].sec < las) {
            ans[a[i].fir] = 1;
            las = a[i].fir;
            tot++;
        }
    }

    tot = n - tot;
    if (tot < 0) {
        cout << "-1" << el;
        return;
    }
    // debugv(ans);
    for (int i = 1; i <= n * 2; i++) {
        if (tot && ans[i] == 0) {
            ans[i] = 1;
            tot--;
        }
    }
    for (int i = 1; i <= n * 2; i++) {
        cout << (ans[i] == 1 ? '(' : ')');
    }
    cout << el;
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

