#include <bits/stdc++.h>

using i64 = long long;
using ld = long double;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using pii = std::pair<int, int>;

const int N = 1e6;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

i64 qpow(i64 x, i64 b)
{
    i64 ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
    return ret;
}

void sovle()
{
    int n;
    std::cin >> n;
    std::vector<std::string> teams;
    std::map<std::string, int> map;
    std::vector info(n, std::vector<a3>());
    int cnt = 0;
    pii num;
    while (n--)
    {
        std::string name, status;
        char no;
        int time;
        std::cin >> name >> no >> time >> status;
        int ac = status == "Accepted";
        int pid = no - 'A';

        int id = map.size();
        if (map.contains(name))
            id = map[name];
        else
        {
            map[name] = id;
            teams.push_back(name);
        }

        info[id].push_back({time, pid, ac});
    }
    n = map.size();
    int cpcnt = 0, cptime = 1e9;
    std::vector accept(n, std::vector<int>(26)), ftime(n, std::vector<int>(26));
    std::vector<int> ft(n), pcnt(n);
    for (int id = 0; id < n; ++id)
    {
        std::ranges::sort(info[id]);
        for (auto [time, pid, ac] : info[id])
        {
            if (time >= 240)
                break;
            if (!accept[id][pid])
            {
                if (ac)
                {
                    accept[id][pid] = 1;
                    ft[id] += time;
                    ft[id] += ftime[id][pid];
                    pcnt[id]++;
                }
                else
                    ftime[id][pid] += 20;
            }
        }
        if (cpcnt < pcnt[id])
        {
            cpcnt = pcnt[id];
            cptime = ft[id];
        }
        else if (cpcnt == pcnt[id])
        {
            cptime = std::min(cptime, ft[id]);
        }
    }
    // std::cerr << cpcnt << ' ' << cptime << '\n';
    std::vector<std::string> ans;
    for (int id = 0; id < n; ++id)
    {
        for (auto [time, pid, ac] : info[id])
        {
            if (time < 240)
                continue;
            if (!accept[id][pid])
            {
                accept[id][pid] = 1;
                ft[id] += time;
                ft[id] += ftime[id][pid];
                pcnt[id]++;
            }
        }
        if (cpcnt < pcnt[id] || cpcnt == pcnt[id] && ft[id] <= cptime)
        {
            ans.push_back(teams[id]);
        }
    }
    std::ranges::sort(ans);
    for (auto x : ans)
        std::cout << x << ' ';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t = 1;
    std::cin >> t;
    while (t--)
    {
        sovle();
        std::cout << '\n';
    }
}