#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ft first
#define sd second

const int inf = 1e8;

using a3 = array<int, 3>;
int n, m, k;
vector< a3 > p;
int ans = inf;
int dx[] = { 0, 1,  0 };
int dy[] = { 1, 0,  0 };

int dx5[] = { -1, 0, 1, 0 , 0 };
int dy5[] = { 0, 1, 0, -1 , 0 };

vector<int> cnt; int ct = 0;
map<pii, int> mp;
vector<array<int, 1010>> g(1010);


void dfs(int id, int now, int use)
{
    if (use >= ans)return;
    if (id == k + 1)
    {
        if (ct == 0)ans = min(ans, use);
        else return;
    }
    else
    {
        int x = p[id][0], y = p[id][1];

        //0
        dfs(id + 1, 0, use);

        //1
        if (now < 3)
            for (int i = 0; i < 3; i++)
            {
                //放置位置
                int a1 = x + dx[i], b1 = y + dy[i];

                for (int j = 0; j < 5; j++)
                {
                    //可攻击位置
                    int ka = a1 + dx5[j], kb = b1 + dy5[j];
                    if (g[ka][kb])
                    {
                        int ui = g[ka][kb];
                        if (--cnt[ui] == 0)ct--;
                    }
                }

                dfs(id, now + 1, use + 1);

                for (int j = 0; j < 5; j++)
                {
                    //可攻击位置
                    int ka = a1 + dx5[j], kb = b1 + dy5[j];
                    if (g[ka][kb])
                    {
                        int ui = g[ka][kb];
                        if (++cnt[ui] == 1)ct++;
                    }
                }
            }

        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    p.resize(k + 1);
    cnt.resize(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    sort(p.begin() + 1, p.end());

    for (int i = 1; i <= k; i++)cnt[i] = p[i][2];
    for (int i = 1; i <= k; i++)
        g[p[i][0]][p[i][1]] = i;

    ct = k;
    dfs(1, 0, 0);
    cout << ans << '\n';
    return 0;
}