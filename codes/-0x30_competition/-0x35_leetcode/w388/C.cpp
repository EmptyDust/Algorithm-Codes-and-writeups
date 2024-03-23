class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        map<string, int> mp;
        int n = arr.size();
        vector<string> ans(n, "");
        for (auto s : arr) {
            int m = s.length();
            for (int i = 0;i < m;++i)for (int j = i;j < m;++j) {
                mp[s.substr(i, j - i + 1)]++;
            }
        }
        for (int k = 0;k < n;++k) {
            int m = s.length();
            for (int i = 0;i < m;++i)for (int j = i;j < m;++j) {
                if (mp[s.substr(i, j - i + 1)] == 1) {
                    if (ans[k] == "" || ans[k] > s.substr(i, j - i + 1))ans[k] = s.substr(i, j - i + 1);
                }
            }
        }
    }
};