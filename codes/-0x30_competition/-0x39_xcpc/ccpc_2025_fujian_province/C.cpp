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
    vector<int> a(n + 1, 0);
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[i] = a[i];
    }
    sort(next(v.begin()), v.end());

    auto check = [&](int x) -> bool
        {
            std::vector<int> t, tmp;
            for (int i = 1;i <= n;++i) {
                tmp.push_back(a[i] >= x);
                if (tmp.size() == 3) {
                    if (std::count(tmp.begin(), tmp.end(), 1) >= 2)tmp = { 1 };
                    else tmp = { 0 };
                }
                if (tmp == std::vector<int>{1}) {
                    t.push_back(1);
                    tmp.clear();
                }
            }
            for (auto x : tmp)t.push_back(x);
            return std::count(t.begin(), t.end(), 1) > std::count(t.begin(), t.end(), 0);
        };

    // check(9);
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        // cout << l << " " << r << " " << mid << endl;
        if (check(v[mid]))
            l = mid;
        else
            r = mid - 1;
    }

    cout << v[l] << el;
}
//010001
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

