#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;
using a6 = std::array<i64, 6>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int m;std::cin >> m;
    std::map<std::string, int> team, problem;
    std::vector<std::string> teamname(1);
    int tuid = 1, puid = 1;
    std::vector<std::vector<a3>> info(1);
    for (int i = 0;i < m;++i) {
        std::string c, p, _s; int t, s;
        std::cin >> c >> p >> t >> _s;
        if (!team[c]) {
            team[c] = tuid++;
            teamname.push_back(c);
            info.push_back({});
        }
        if (!problem[p]) {
            problem[p] = puid++;
        }
        if (_s == "accepted")s = 1;
        else s = 0;
        info[team[c]].push_back({ problem[p],t,s });
        // std::cout << info[team[c]].size() << '\n';
    }
    // std::cout << team["TS1"];
    std::vector<i64> firstm(puid), accept(puid), accept2(puid), wa(puid);
    std::vector<a6> res;
    // 通过题数 罚时 是否使用 最差情况 id
    std::vector<int> vaild(tuid);
    int n = 0;
    for (int tid = 1;tid < tuid;++tid) {
        std::vector<int> mt;
        i64 time = 0, cnt = 0;
        for (auto [p, t, s] : info[tid]) {
            if (accept[p]) {
                if (!accept2[p])accept2[p] = t;
                continue;
            }
            mt.push_back(p);
            if (!firstm[p])firstm[p] = t;
            if (s) accept[p] = t;
            else wa[p]++;
        }
        ranges::sort(mt);
        mt.erase(std::unique(mt.begin(), mt.end()), mt.end());
        i64 btime = 0, bcnt = 0;
        i64 wtime = 0, wcnt = 0;
        for (auto p : mt) {
            if (accept[p]) {
                cnt++;
                time += accept[p] + wa[p] * 20;
                if (!bcnt) {
                    btime = std::max(btime, wa[p] * 20 + accept[p] - firstm[p]);
                }
                if (accept2[p]) {
                    if (!wcnt) {
                        wtime = std::max(wtime, accept2[p]);
                    }
                }
                else {
                    if (wcnt) {
                        wtime = std::min(wtime, accept[p]);
                    }
                    else {
                        wcnt = 1;
                        wtime = accept[p];
                    }
                }
            }
            else {
                if (bcnt) {
                    btime = std::min(btime, firstm[p]);
                }
                else {
                    bcnt = 1;
                    btime = firstm[p];
                }
            }
            firstm[p] = 0;
            accept[p] = 0;
            accept2[p] = 0;
            wa[p] = 0;
        }
        if (bcnt) {
            res.push_back({ cnt + 1,time + btime,0,0,0,tid });
        }
        else {
            res.push_back({ cnt ,time - btime,0,0,0,tid });
        }
        // if (tid == 1) {
        //     std::cout << teamname[tid] << ' ' << cnt << ' ' << time << "\n";
        //     std::cout << mt.size() << '\n';
        // }
        res.push_back({ cnt ,time,1,cnt - wcnt,time - wtime,tid });
        vaild[tid] = (cnt >= 1);
        n += vaild[tid];
    }
    ranges::sort(res, [&](a6 a, a6 b) {
        if (a[0] != b[0])return a[0] > b[0];
        return a < b;
        });
    std::vector<int> best(tuid, inf);
    i64 precnt = inf, pretime = 0;
    int pretc = 0;
    std::vector<int> ans;
    // std::cout << (n+9)/10 << ' ';
    for (auto [cnt, time, canu, wcnt, wtime, tid] : res) {
        // std::cout << precnt << ' ' << pretime << "\n";
        if (canu) {
            if (cnt > precnt || cnt == precnt && time < pretime) {
                if (cnt && pretc - 1 < std::min(35, (n + (1 - vaild[tid]) + 9) / 10))
                    ans.push_back(tid);
            }
            if (precnt > wcnt) {
                precnt = wcnt;
                pretime = wtime;
            }
            else if (precnt == wcnt) {
                pretime = std::min(pretime, wtime);
            }
            pretc++;
        }
        else {
            if (cnt && pretc < std::min(35, (n + (1 - vaild[tid]) + 9) / 10))
                ans.push_back(tid);
            continue;
        }
    }
    ranges::sort(ans);
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    std::cout << ans.size() << '\n';
    for (int x : ans)std::cout << teamname[x] << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}