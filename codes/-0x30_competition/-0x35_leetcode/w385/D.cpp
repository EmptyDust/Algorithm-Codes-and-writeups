#include <bits/stdc++.h>
using namespace std;
struct dic {
    struct dic* dics[26];
    map<string, int> ss;
    void insert(string s) {
        dic* t = this;
        for (char ch : s) {
            int c = ch - 'a';
            if (!t->dics[c])t->dics[c] = new dic();
            t = t->dics[c];
        }
        t->ss[s]++;
    }
    int qry(string s) {
        dic* t = this;
        int cnt = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (!t->dics[c])return cnt;
            t = t->dics[c];
            for (auto [str, ct] : t->ss) {
                int n = s.length(), m = str.length();
                bool f = true;
                for (int i = n - m, j = 0;i < n;++i, ++j)if (s[i] != str[j]) {
                    f = false;
                    break;
                }
                cnt += ct * f;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        dic* d = new dic();
        long long ans = 0;
        for (auto word : words) {
            ans += d->qry(word);
            d->insert(word);
        }
        return ans;
    }
};