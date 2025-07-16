#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvii vector<vector<pair<int,int>>>
#define vvll vector<vector<pair<ll,ll>>>
#define vst vector<string>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mkunique(x) sort(all(x));(x).erase(unique(all(x)),(x).end())
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod = 998244353, MAX = 435;
const ll INF = 15LL << 56;

ll loco[MAX][MAX];
ll N;
ll A[MAX], rui[MAX];
ll dp[MAX][MAX][MAX];

int main() {

    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;cin >> Q;
    while (Q--) {
        cin >> N;
        for (int i = 0;i <= N;i++) {
            A[i] = 0;
            rui[i] = 0;
            for (int j = i;j <= N;j++) {
                loco[i][j] = 0;
                for (int k = 0;k <= N;k++) {
                    dp[i][j][k] = INF;
                }
            }
        }
        for (int i = 0;i < N;i++) {
            cin >> A[i];
            rui[i + 1] = rui[i] + A[i];
        }

        auto f = [&](ll l, ll r) {
            return rui[r] - rui[l];
            };

        for (int i = 0;i < N;i++) {
            for (int j = i + 1;j <= N;j++) {
                ll len = f(i, j);
                for (int k = 0;k <= 60;k++) {
                    if ((1LL << k) >= len) {
                        loco[i][j] = k;
                        break;
                    }
                }
            }
        }

        for (int len = 1;len <= N;len++) {
            for (int l = 0;l + len <= N;l++) {
                int r = l + len;
                if (len == 1) {
                    for (int k = 0;k <= N;k++) {
                        dp[l][r][k] = 0;
                    }
                    continue;
                }
                vll S;
                for (int s = 0;s < l;s++) {
                    S.pb(mp(abs(f(s, l) - f(l, r)), s));
                }
                for (int s = r + 1;s <= N;s++) {
                    S.pb(mp(abs(f(l, r) - f(r, s)), s));
                }
                for (int k = l + 1;k < r;k++) {
                    S.pb(mp(abs(f(l, k) - f(k, r)), ~k));
                }
                sort(all(S));

                ll mi = INF;
                for (auto [x, id] : S) {
                    if (id < 0) {
                        id = ~id;
                        chmin(mi, dp[l][id][r] + dp[id][r][l] + loco[l][r] * min(f(l, id), f(id, r)));
                    }
                    else {
                        dp[l][r][id] = mi;
                    }
                }

            }
        }

        for (int m = 1;m < N;m++) {
            if (dp[0][m][N] == INF || dp[m][N][0] == INF) cout << -1 << " ";
            else {
                ll res = dp[0][m][N] + dp[m][N][0] + loco[0][N] * min(f(0, m), f(m, N));
                cout << res << " ";
            }
        }
        cout << "\n";
    }
}


